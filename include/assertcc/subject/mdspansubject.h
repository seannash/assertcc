#pragma once

#include <assertcc/subject/base.h>
#include <assertcc/proposition/hassizepropositions.h>
#include <assertcc/proposition/isemptypropositions.h>

#if __cpp_lib_mdspan >= 202207L

#include <mdspan>

using namespace std;

namespace {

template<typename T>
concept Printable = requires(std::ostream& os, T value) {
    { os << value } -> std::convertible_to<std::ostream&>;
};

template<size_t Rank, typename... Args>
void print_mdspan_dimension_helper(std::ostream& os, size_t current_dim, size_t indent_level, Args&&... args) {
    if constexpr (sizeof...(Args) > 0) {
        os << std::string(indent_level, ' ') << "[\n";
        print_mdspan_dimension_helper<Rank>(os, current_dim + 1, indent_level + 2, std::forward<Args>(args)...);
        os << std::string(indent_level, ' ') << "]\n";
    }
}



template<Printable ElementType, class Extents, class Layout, class Accessor>
void pretty_print_nd(const std::mdspan<ElementType, Extents, Layout, Accessor>& span, std::ostream& os,
                    int precision, int width) {
    using index_type = typename Extents::index_type;
    constexpr size_t rank = Extents::rank();
    std::function<void(std::vector<index_type>&, size_t)> print_recursive;    
    print_recursive = [&](std::vector<index_type>& indices, size_t dim) {
        const size_t indent = dim * 2;
        const std::string indent_str(indent, ' ');
        if (dim == rank) {
            os << std::setw(width) << std::span(indices.data());
            return;
        }
        os << indent_str << "[\n";
        for (index_type i = 0; i < span.extent(dim); ++i) {
            indices[dim] = i;
            if (dim == rank - 1) {
                os << std::string(indent + 2, ' ');
                for (index_type j = 0; j < span.extent(dim); ++j) {
                    indices[dim] = j;
                    os << std::setw(width) << span(indices.data());
                    if (j < span.extent(dim) - 1) os << ", ";
                }
                os << "\n";
                break;
            } else {
                print_recursive(indices, dim + 1);
                
                if (i < span.extent(dim) - 1) {
                    os << ",\n";
                }
            }
        }  
        os << indent_str << "]";
    };    
    std::vector<index_type> indices(rank, 0);
    print_recursive(indices, 0);
}

template<Printable ElementType, class Extents, class Layout, class Accessor>
void pretty_print(const std::mdspan<ElementType, Extents, Layout, Accessor>& span, std::ostream& os = std::cout, 
                 int precision = 6, int width = 10) {
    using index_type = typename Extents::index_type;
    constexpr size_t rank = Extents::rank();
    
    if constexpr (std::is_floating_point_v<ElementType>) {
        os << std::fixed << std::setprecision(precision);
    }

    if constexpr (rank == 0) {
        os << span[];
    } else if constexpr (rank == 1) {
        os << "[ ";
        for (index_type i = 0; i < span.extent(0); ++i) {
            os << std::setw(width) << span[i];
            if (i < span.extent(0) - 1) os << ", ";
        }
        os << " ]";
    } else {
        pretty_print_nd(span, os, precision, width);
    }
}

template<Printable ElementType, class Extents, class Layout, class Accessor>
std::string to_string(const std::mdspan<ElementType, Extents, Layout, Accessor>& span, 
                     int precision = 6, int width = 10) {
    std::ostringstream oss;
    pretty_print(span, oss, precision, width);
    return oss.str();
}

} // namespace

namespace assertcc::subject {
template <typename T>
class MdspanSubject : public virtual Base<T>,
                      public proposition::HasSizePropositions<MdspanSubject<T>, T>,
                      public proposition::IsEmptyPropositions<MdspanSubject<T>, T> {
 public:

  MdspanSubject(bool failOnError, const char* file, int line, const T& v)
      : Base<T>(failOnError, file, line), d_object(v) {}

 private:
  T d_object;

  const T* getObject() const override { return &d_object; }
  const std::string getObjectAsString(const T& other) const override {
    std::stringstream ss;
    ss << "mdspan with elements: ";
    ss << to_string(other);
    return ss.str();
  }
};

} // namespace assertcc::subject

#endif