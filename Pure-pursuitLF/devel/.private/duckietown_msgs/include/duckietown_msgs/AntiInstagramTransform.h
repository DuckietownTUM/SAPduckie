// Generated by gencpp from file duckietown_msgs/AntiInstagramTransform.msg
// DO NOT EDIT!


#ifndef DUCKIETOWN_MSGS_MESSAGE_ANTIINSTAGRAMTRANSFORM_H
#define DUCKIETOWN_MSGS_MESSAGE_ANTIINSTAGRAMTRANSFORM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace duckietown_msgs
{
template <class ContainerAllocator>
struct AntiInstagramTransform_
{
  typedef AntiInstagramTransform_<ContainerAllocator> Type;

  AntiInstagramTransform_()
    : header()
    , s()  {
      s.assign(0.0);
  }
  AntiInstagramTransform_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , s()  {
  (void)_alloc;
      s.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef boost::array<double, 6>  _s_type;
  _s_type s;





  typedef boost::shared_ptr< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> const> ConstPtr;

}; // struct AntiInstagramTransform_

typedef ::duckietown_msgs::AntiInstagramTransform_<std::allocator<void> > AntiInstagramTransform;

typedef boost::shared_ptr< ::duckietown_msgs::AntiInstagramTransform > AntiInstagramTransformPtr;
typedef boost::shared_ptr< ::duckietown_msgs::AntiInstagramTransform const> AntiInstagramTransformConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace duckietown_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'duckietown_msgs': ['/code/catkin_ws/src/dt-ros-commons/packages/duckietown_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d8691e07ae6615fec4d91101863288cf";
  }

  static const char* value(const ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd8691e07ae6615feULL;
  static const uint64_t static_value2 = 0xc4d91101863288cfULL;
};

template<class ContainerAllocator>
struct DataType< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >
{
  static const char* value()
  {
    return "duckietown_msgs/AntiInstagramTransform";
  }

  static const char* value(const ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
float64[6] s\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.s);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AntiInstagramTransform_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::duckietown_msgs::AntiInstagramTransform_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "s[]" << std::endl;
    for (size_t i = 0; i < v.s.size(); ++i)
    {
      s << indent << "  s[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.s[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // DUCKIETOWN_MSGS_MESSAGE_ANTIINSTAGRAMTRANSFORM_H
