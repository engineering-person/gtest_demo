aux_source_directory(. SRC_LIST)
add_library(cal SHARED ${SRC_LIST})

# avoid.h 的公开接口用到了 sensor_msgs / geometry_msgs，因此必须 PUBLIC 传播给使用者
target_include_directories(cal PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
