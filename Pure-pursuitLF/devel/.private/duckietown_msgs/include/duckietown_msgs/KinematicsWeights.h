// Generated by gencpp from file duckietown_msgs/KinematicsWeights.msg
// DO NOT EDIT!


#ifndef DUCKIETOWN_MSGS_MESSAGE_KINEMATICSWEIGHTS_H
#define DUCKIETOWN_MSGS_MESSAGE_KINEMATICSWEIGHTS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace duckietown_msgs
{
template <class ContainerAllocator>
struct KinematicsWeights_
{
  typedef KinematicsWeights_<ContainerAllocator> Type;

  KinematicsWeights_()
    : weights()  {
    }
  KinematicsWeights_(const ContainerAllocator& _alloc)
    : weights(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _weights_type;
  _weights_type weights;





  typedef boost::shared_ptr< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> const> ConstPtr;

}; // struct KinematicsWeights_

typedef ::duckietown_msgs::KinematicsWeights_<std::allocator<void> > KinematicsWeights;

typedef boost::shared_ptr< ::duckietown_msgs::KinematicsWeights > KinematicsWeightsPtr;
typedef boost::shared_ptr< ::duckietown_msgs::KinematicsWeights const> KinematicsWeightsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace duckietown_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'duckietown_msgs': ['/code/catkin_ws/src/dt-ros-commons/packages/duckietown_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6904a09d2a677bf07bc600ffaa092ae8";
  }

  static const char* value(const ::duckietown_msgs::KinematicsWeights_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6904a09d2a677bf0ULL;
  static const uint64_t static_value2 = 0x7bc600ffaa092ae8ULL;
};

template<class ContainerAllocator>
struct DataType< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >
{
  static const char* value()
  {
    return "duckietown_msgs/KinematicsWeights";
  }

  static const char* value(const ::duckietown_msgs::KinematicsWeights_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64[] weights\n\
";
  }

  static const char* value(const ::duckietown_msgs::KinematicsWeights_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.weights);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct KinematicsWeights_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::duckietown_msgs::KinematicsWeights_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::duckietown_msgs::KinematicsWeights_<ContainerAllocator>& v)
  {
    s << indent << "weights[]" << std::endl;
    for (size_t i = 0; i < v.weights.size(); ++i)
    {
      s << indent << "  weights[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.weights[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DUCKIETOWN_MSGS_MESSAGE_KINEMATICSWEIGHTS_H
