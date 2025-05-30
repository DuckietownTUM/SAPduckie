// Generated by gencpp from file my_ground_projection/GetImageCoord.msg
// DO NOT EDIT!


#ifndef MY_GROUND_PROJECTION_MESSAGE_GETIMAGECOORD_H
#define MY_GROUND_PROJECTION_MESSAGE_GETIMAGECOORD_H

#include <ros/service_traits.h>


#include <my_ground_projection/GetImageCoordRequest.h>
#include <my_ground_projection/GetImageCoordResponse.h>


namespace my_ground_projection
{

struct GetImageCoord
{

typedef GetImageCoordRequest Request;
typedef GetImageCoordResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetImageCoord
} // namespace my_ground_projection


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::my_ground_projection::GetImageCoord > {
  static const char* value()
  {
    return "590f09a60b9d5d3e1b4384278b6e2b2f";
  }

  static const char* value(const ::my_ground_projection::GetImageCoord&) { return value(); }
};

template<>
struct DataType< ::my_ground_projection::GetImageCoord > {
  static const char* value()
  {
    return "my_ground_projection/GetImageCoord";
  }

  static const char* value(const ::my_ground_projection::GetImageCoord&) { return value(); }
};


// service_traits::MD5Sum< ::my_ground_projection::GetImageCoordRequest> should match 
// service_traits::MD5Sum< ::my_ground_projection::GetImageCoord > 
template<>
struct MD5Sum< ::my_ground_projection::GetImageCoordRequest>
{
  static const char* value()
  {
    return MD5Sum< ::my_ground_projection::GetImageCoord >::value();
  }
  static const char* value(const ::my_ground_projection::GetImageCoordRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::my_ground_projection::GetImageCoordRequest> should match 
// service_traits::DataType< ::my_ground_projection::GetImageCoord > 
template<>
struct DataType< ::my_ground_projection::GetImageCoordRequest>
{
  static const char* value()
  {
    return DataType< ::my_ground_projection::GetImageCoord >::value();
  }
  static const char* value(const ::my_ground_projection::GetImageCoordRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::my_ground_projection::GetImageCoordResponse> should match 
// service_traits::MD5Sum< ::my_ground_projection::GetImageCoord > 
template<>
struct MD5Sum< ::my_ground_projection::GetImageCoordResponse>
{
  static const char* value()
  {
    return MD5Sum< ::my_ground_projection::GetImageCoord >::value();
  }
  static const char* value(const ::my_ground_projection::GetImageCoordResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::my_ground_projection::GetImageCoordResponse> should match 
// service_traits::DataType< ::my_ground_projection::GetImageCoord > 
template<>
struct DataType< ::my_ground_projection::GetImageCoordResponse>
{
  static const char* value()
  {
    return DataType< ::my_ground_projection::GetImageCoord >::value();
  }
  static const char* value(const ::my_ground_projection::GetImageCoordResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MY_GROUND_PROJECTION_MESSAGE_GETIMAGECOORD_H
