FROM debian:bookworm

# Install prerequisites
RUN apt-get update && apt-get install -y \
    gnupg \
    wget \
    apt-transport-https \
    ca-certificates \
    lsb-release \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Add LLVM/Clang nightly repository (using newer method instead of deprecated apt-key)
RUN apt-get update && apt-get install -y gpg && \
    wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | gpg --dearmor -o /usr/share/keyrings/llvm-snapshot.gpg && \
    echo "deb [signed-by=/usr/share/keyrings/llvm-snapshot.gpg] https://apt.llvm.org/bookworm/ llvm-toolchain-bookworm-20 main" >> /etc/apt/sources.list.d/llvm-nightly.list && \
    echo "deb-src [signed-by=/usr/share/keyrings/llvm-snapshot.gpg] https://apt.llvm.org/bookworm/ llvm-toolchain-bookworm-20 main" >> /etc/apt/sources.list.d/llvm-nightly.list

# Update and install build tools
RUN apt-get update && apt-get install -y \
    cmake

# Update and install Clang 20 (nightly)
RUN apt-get update && apt-get install -y \
    clang-20 \
    lld-20 \
    lldb-20 \
    libc++-20-dev \
    libc++abi-20-dev \
    libunwind-20-dev \
    libclang-rt-20-dev

RUN rm -rf /var/lib/apt/lists/*

# Set environment variables for Clang 20
ENV CC=/usr/bin/clang-20
ENV CXX=/usr/bin/clang++-20
ENV LDFLAGS="-fuse-ld=lld-20"
ENV CXXFLAGS="-stdlib=libc++"

# Create symbolic links for easier use
RUN ln -s /usr/bin/clang-20 /usr/bin/clang && \
    ln -s /usr/bin/clang++-20 /usr/bin/clang++ && \
    ln -s /usr/bin/lld-20 /usr/bin/lld && \
    ln -s /usr/bin/lldb-20 /usr/bin/lldb

# Default command
CMD ["/bin/bash"]