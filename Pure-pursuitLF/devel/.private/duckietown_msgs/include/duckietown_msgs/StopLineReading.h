// Generated by gencpp from file duckietown_msgs/StopLineReading.msg
// DO NOT EDIT!


#ifndef DUCKIETOWN_MSGS_MESSAGE_STOPLINEREADING_H
#define DUCKIETOWN_MSGS_MESSAGE_STOPLINEREADING_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Point.h>

namespace duckietown_msgs
{
template <class ContainerAllocator>
struct StopLineReading_
{
  typedef StopLineReading_<ContainerAllocator> Type;

  StopLineReading_()
    : header()
    , stop_line_detected(false)
    , at_stop_line(false)
    , stop_line_point()  {
    }
  StopLineReading_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , stop_line_detected(false)
    , at_stop_line(false)
    , stop_line_point(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _stop_line_detected_type;
  _stop_line_detected_type stop_line_detected;

   typedef uint8_t _at_stop_line_type;
  _at_stop_line_type at_stop_line;

   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _stop_line_point_type;
  _stop_line_point_type stop_line_point;





  typedef boost::shared_ptr< ::duckietown_msgs::StopLineReading_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::duckietown_msgs::StopLineReading_<ContainerAllocator> const> ConstPtr;

}; // struct StopLineReading_

typedef ::duckietown_msgs::StopLineReading_<std::allocator<void> > StopLineReading;

typedef boost::shared_ptr< ::duckietown_msgs::StopLineReading > StopLineReadingPtr;
typedef boost::shared_ptr< ::duckietown_msgs::StopLineReading const> StopLineReadingConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::duckietown_msgs::StopLineReading_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::duckietown_msgs::StopLineReading_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::duckietown_msgs::StopLineReading_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::duckietown_msgs::StopLineReading_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >
{
  static const char* value()
  {
    return "735fe9e9ff1e4d7460bbf69ab2720ae0";
  }

  static const char* value(const ::duckietown_msgs::StopLineReading_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x735fe9e9ff1e4d74ULL;
  static const uint64_t static_value2 = 0x60bbf69ab2720ae0ULL;
};

template<class ContainerAllocator>
struct DataType< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >
{
  static const char* value()
  {
    return "duckietown_msgs/StopLineReading";
  }

  static const char* value(const ::duckietown_msgs::StopLineReading_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
bool stop_line_detected\n\
bool at_stop_line\n\
geometry_msgs/Point stop_line_point #this is in the \"lane frame\"\n\
\n\
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
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::duckietown_msgs::StopLineReading_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.stop_line_detected);
      stream.next(m.at_stop_line);
      stream.next(m.stop_line_point);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct StopLineReading_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::duckietown_msgs::StopLineReading_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::duckietown_msgs::StopLineReading_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "stop_line_detected: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.stop_line_detected);
    s << indent << "at_stop_line: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.at_stop_line);
    s << indent << "stop_line_point: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.stop_line_point);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DUCKIETOWN_MSGS_MESSAGE_STOPLINEREADING_H
