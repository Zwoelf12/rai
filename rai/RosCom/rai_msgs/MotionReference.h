/*  ------------------------------------------------------------------
    Copyright (c) 2017 Marc Toussaint
    email: marc.toussaint@informatik.uni-stuttgart.de

    This code is distributed under the MIT License.
    Please see <root-path>/LICENSE for details.
    --------------------------------------------------------------  */

// Generated by gencpp from file rai_msgs/MotionReference.msg
// DO NOT EDIT!

#ifndef RAI_MSGS_MESSAGE_MOTIONREFERENCE_H
#define RAI_MSGS_MESSAGE_MOTIONREFERENCE_H

#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <rai_msgs/arr.h>
#include <rai_msgs/arr.h>

namespace rai_msgs {
template <class ContainerAllocator>
struct MotionReference_ {
  typedef MotionReference_<ContainerAllocator> Type;
  
  MotionReference_()
    : x()
    , t()
    , joints()
    , append(false)
    , revision(0)  {
  }
  MotionReference_(const ContainerAllocator& _alloc)
    : x(_alloc)
    , t(_alloc)
    , joints(_alloc)
    , append(false)
    , revision(0)  {
    (void)_alloc;
  }
  
  typedef  ::rai_msgs::arr_<ContainerAllocator>  _x_type;
  _x_type x;
  
  typedef  ::rai_msgs::arr_<ContainerAllocator>  _t_type;
  _t_type t;
  
  typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _joints_type;
  _joints_type joints;
  
  typedef uint8_t _append_type;
  _append_type append;
  
  typedef int32_t _revision_type;
  _revision_type revision;
  
  typedef boost::shared_ptr< ::rai_msgs::MotionReference_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rai_msgs::MotionReference_<ContainerAllocator> const> ConstPtr;
  
}; // struct MotionReference_

typedef ::rai_msgs::MotionReference_<std::allocator<void> > MotionReference;

typedef boost::shared_ptr< ::rai_msgs::MotionReference > MotionReferencePtr;
typedef boost::shared_ptr< ::rai_msgs::MotionReference const> MotionReferenceConstPtr;

// constants requiring out of line definition

template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rai_msgs::MotionReference_<ContainerAllocator> & v) {
  ros::message_operations::Printer< ::rai_msgs::MotionReference_<ContainerAllocator> >::stream(s, "", v);
  return s;
}

} // namespace rai_msgs

namespace ros {
namespace message_traits {

// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/msg'], 'rai_msgs': ['/home/mtoussai/git/mlr/share/rai/rai/RosCom/rai_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']

template <class ContainerAllocator>
struct IsFixedSize< ::rai_msgs::MotionReference_<ContainerAllocator> >
  : FalseType
{ };

template <class ContainerAllocator>
struct IsFixedSize< ::rai_msgs::MotionReference_<ContainerAllocator> const>
    : FalseType
{ };

template <class ContainerAllocator>
struct IsMessage< ::rai_msgs::MotionReference_<ContainerAllocator> >
  : TrueType
{ };

template <class ContainerAllocator>
struct IsMessage< ::rai_msgs::MotionReference_<ContainerAllocator> const>
    : TrueType
{ };

template <class ContainerAllocator>
struct HasHeader< ::rai_msgs::MotionReference_<ContainerAllocator> >
  : FalseType
{ };

template <class ContainerAllocator>
struct HasHeader< ::rai_msgs::MotionReference_<ContainerAllocator> const>
    : FalseType
{ };

template<class ContainerAllocator>
struct MD5Sum< ::rai_msgs::MotionReference_<ContainerAllocator> > {
  static const char* value() {
    return "45ce7d1cbfa9c6225425ca2ff1835ac9";
  }
  
  static const char* value(const ::rai_msgs::MotionReference_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x45ce7d1cbfa9c622ULL;
  static const uint64_t static_value2 = 0x5425ca2ff1835ac9ULL;
};

template<class ContainerAllocator>
struct DataType< ::rai_msgs::MotionReference_<ContainerAllocator> > {
  static const char* value() {
    return "rai_msgs/MotionReference";
  }
  
  static const char* value(const ::rai_msgs::MotionReference_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rai_msgs::MotionReference_<ContainerAllocator> > {
  static const char* value() {
    return "arr x\n\
arr t\n\
string[] joints\n\
bool append\n\
int32 revision\n\
\n\
================================================================================\n\
MSG: rai_msgs/arr\n\
uint32[] dim\n\
float64[] data\n\
";
  }
  
  static const char* value(const ::rai_msgs::MotionReference_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros {
namespace serialization {

template<class ContainerAllocator> struct Serializer< ::rai_msgs::MotionReference_<ContainerAllocator> > {
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m) {
    stream.next(m.x);
    stream.next(m.t);
    stream.next(m.joints);
    stream.next(m.append);
    stream.next(m.revision);
  }
  
  ROS_DECLARE_ALLINONE_SERIALIZER
}; // struct MotionReference_

} // namespace serialization
} // namespace ros

namespace ros {
namespace message_operations {

template<class ContainerAllocator>
struct Printer< ::rai_msgs::MotionReference_<ContainerAllocator> > {
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rai_msgs::MotionReference_<ContainerAllocator>& v) {
    s << indent << "x: ";
    s << std::endl;
    Printer< ::rai_msgs::arr_<ContainerAllocator> >::stream(s, indent + "  ", v.x);
    s << indent << "t: ";
    s << std::endl;
    Printer< ::rai_msgs::arr_<ContainerAllocator> >::stream(s, indent + "  ", v.t);
    s << indent << "joints[]" << std::endl;
    for(size_t i = 0; i < v.joints.size(); ++i) {
      s << indent << "  joints[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.joints[i]);
    }
    s << indent << "append: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.append);
    s << indent << "revision: ";
    Printer<int32_t>::stream(s, indent + "  ", v.revision);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RAI_MSGS_MESSAGE_MOTIONREFERENCE_H
