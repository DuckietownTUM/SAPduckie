# parameters
ARG REPO_NAME="coral"

# ==================================================>
# ==> Do not change this code
ARG ARCH=arm64v8
ARG MAJOR=daffy-staging
ARG BASE_TAG=${MAJOR}-${ARCH}
ARG BASE_IMAGE=dt-ros-commons



# define base image
FROM duckietown/${BASE_IMAGE}:${BASE_TAG}


# define repository path
ARG REPO_NAME
ARG REPO_PATH="${CATKIN_WS_DIR}/src/${REPO_NAME}"
WORKDIR "${REPO_PATH}"

# create repo directory
RUN mkdir -p "${REPO_PATH}"

# copy dependencies files only
COPY ./dependencies-apt.txt "${REPO_PATH}/"
COPY ./dependencies-py.txt "${REPO_PATH}/"

# Python 3 requirement
RUN apt-get update
RUN apt-get install -y python3-pip
RUN ln -s /usr/bin/python3 /usr/bin/python 
RUN pip3 install -r ${REPO_PATH}/dependencies-py.txt

#RUN echo "deb http://packages.ros.org/ros/ubuntu focal main" > /etc/apt/sources.list.d/ros1-latest.list
#RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654



# install apt dependencies
RUN apt-get update \
  && apt-get install -y --no-install-recommends \
    $(awk -F: '/^[^#]/ { print $1 }' dependencies-apt.txt | uniq) \
  && rm -rf /var/lib/apt/lists/*

# Install TensorFlow
RUN pip3 install --upgrade pip
RUN pip3 install tensorflow-aarch64==2.7.4
#RUN pip3 install tensorflow-aarch64==1.2
# Copy the TensorFlow wheel file into the Docker image

# Clone and install tf_trt_models
RUN apt-get update && apt-get install -y git
RUN git clone --recursive https://github.com/NVIDIA-Jetson/tf_trt_models.git
RUN cd tf_trt_models && ./install.sh

# copy the source code
COPY . "${REPO_PATH}/"

# build packages
RUN . /opt/ros/${ROS_DISTRO}/setup.sh && \
  catkin build \
    --workspace ${CATKIN_WS_DIR}/

# define launch script
ENV LAUNCHFILE "${REPO_PATH}/launch.sh"

# define command
CMD ["bash", "-c", "${LAUNCHFILE}"]
# <== Do not change this code
# <==================================================

# maintainer
LABEL maintainer="Parth Karkar (parthkarkar70@gmail.com)"
