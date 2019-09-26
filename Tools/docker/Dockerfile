FROM ubuntu

RUN apt-get update && apt-get install -y \
  sudo \
  bash \
  cpio \
  wget \
  vim \
  emacs \
  tmux \
  curl \
  patch \
  unzip \
  bzip2 \
  mlocate \
  gawk \
  bison \
  flex \
  git \
  subversion \
  mercurial \
  build-essential \
  gfortran \
  clang \
  autoconf \
  automake \
  cmake \
  cmake-data\
  cmake-curses-gui \
  gcc \
  g++ \
  doxygen \
  texinfo \
  texlive \
  texlive-latex-extra\
  pkg-config \
  environment-modules \
  gcovr \
  lcov \
  cppcheck \
  libcppunit-dev \
  vera++ \
  valgrind \
  python2.7 \
  python-pip \
  openjdk-8-jre && \
  apt-get autoremove -y

RUN pip install --upgrade pip && \
    pip install numpy scipy scikit-learn matplotlib pandas pytest ipython pytest-cov coverage==3.7.1 scan-build

RUN groupadd -f -g 1000 gitlab && \
    useradd -u 1000 -g gitlab -ms /bin/bash gitlab && \
    mkdir /builds && \
    chown -R gitlab:gitlab /builds && \
    echo "gitlab:gitlab" | chpasswd && adduser gitlab sudo

ENV version_rats 2.4
RUN mkdir -p /home/gitlab/sonar && \
    cd /home/gitlab/sonar/ && \
    wget https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/rough-auditing-tool-for-security/rats-${version_rats}.tgz && \
    tar -xzvf rats-${version_rats}.tgz && \
    cd rats-${version_rats} && \
    ./configure && make && sudo make install

RUN cd /home/gitlab/sonar && \
    wget https://github.com/eriwen/lcov-to-cobertura-xml/archive/1.6.tar.gz && \
    tar xvf 1.6.tar.gz

RUN cd /home/gitlab/sonar && \
    git clone https://github.com/SonarOpenCommunity/sonar-cxx.git && \
    chmod +x /home/gitlab/sonar/sonar-cxx/sonar-cxx-plugin/src/tools/vera++Report2checkstyleReport.perl

RUN cd /home/gitlab/sonar && \
    wget https://sonarsource.bintray.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-3.0.3.778-linux.zip && \
    unzip sonar-scanner-cli-3.0.3.778-linux.zip

RUN chown -R gitlab:gitlab /home/gitlab/

USER gitlab
# change the default shell to be bash
SHELL ["/bin/bash", "-c"]
ENV PATH /home/gitlab/sonar/lcov-to-cobertura-xml-1.6/lcov_cobertura:$PATH
ENV PATH /home/gitlab/sonar/sonar-cxx/sonar-cxx-plugin/src/tools:$PATH
ENV PATH /home/gitlab/sonar/sonar-scanner-3.0.3.778-linux/bin:$PATH

WORKDIR /builds
