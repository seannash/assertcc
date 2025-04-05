include_directories(../include)

find_package(GTest)
find_package(Threads)

add_executable(assertcc_unittests
    bool.t.cc
    complex.t.cc
    double.t.cc
    float.t.cc
    function.t.cc
    int.t.cc
    iterators.t.cc
    map.t.cc
    multimap.t.cc
    multiset.t.cc
    optional.t.cc
    pair.t.cc
    queue.t.cc
    pointers.t.cc
    priority_queue.t.cc
    set.t.cc
    shared_ptr.t.cc
    span.t.cc
    stack.t.cc
    string.t.cc
    string_view.t.cc
    unique_ptr.t.cc
    unordered_map.t.cc
    unordered_multimap.t.cc
    unordered_set.t.cc
    user_class.t.cc
    user_subject.t.cc
    weak_ptr.t.cc
)

target_link_libraries(assertcc_unittests Threads::Threads GTest::Main)
include_directories(assertcc_unittests assertcc)
set_property(TARGET assertcc_unittests PROPERTY CXX_STANDARD 23)

add_test(
    NAME assertcc_unittests
    COMMAND assertcc_unittests
)
