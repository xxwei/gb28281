#要求CMake的最低版本为3.5
cmake_minimum_required(VERSION 3.5)

#设置项目名词
project(gb28281)

#用于将当前目录下的所有源文件的名字保存在变量 DIR_SRCS 中  
aux_source_directory(. CUR_SRCS) 

aux_source_directory(./src DIR_SRCS) 
#添加子目录
#add_subdirectory(src)


#添加头文件搜索路径  
include_directories(${PROJECT_SOURCE_DIR}/include)

#添加库文件搜索路径  
link_directories(${PROJECT_BINARY_DIR}/lib)

#添加库文件
link_libraries("libeXosip2.so" "libosip2.so" "libosipparser2.so" "libpthread.so")


#c++11
add_definitions(-std=c++11)

#指定可执行程序输出路径为运行cmake时路径的bin子路径  
#默认是输出到运行cmake命令时的路径  
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


#用于指定从一组源文件 source1 source2 … sourceN(在变量DIR_SRCS中定义)   
#编译出一个可执行文件且命名为gb28281 
add_executable(gb28281 ${CUR_SRCS} ${DIR_SRCS} )