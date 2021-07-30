project('o3de', 'c', 'cpp',
   default_options: ['cpp_std=c++17'])

add_project_arguments('-msse4.1', language: 'cpp')
add_project_arguments('-msse4.1', language: 'c')

add_project_arguments('-DAZ_BUILD_CONFIGURATION_TYPE="debug"', language: 'cpp')

cpp = meson.get_compiler('cpp')

thread_dep = dependency('threads')
unwind_dep = dependency('libunwind')
dl_dep = cpp.find_library('dl', required: false)
zlib_dep = dependency('zlib')
rapidjson_dep = dependency('rapidjson')
rapidxml_dep = dependency('rapidxml')
zstd_dep = dependency('libzstd')
lua_dep = dependency('lua')
cityhash_dep = dependency('cityhash')
gtest_dep = dependency('gtest')
gmock_dep = dependency('gmock')
lz4_dep = dependency('liblz4')
md5_dep = dependency('md5') # Would probably make more sense to use OpenSSL's md5 instead.
qt5_dep = dependency('qt5', modules: ['Gui', 'Widgets', 'Core'], private_headers: true)
qt5svg_dep = dependency('qt5', modules: ['Svg'], private_headers: true)
qt5xml_dep = dependency('qt5', modules: ['Xml'], private_headers: true)
qt5_mod = import('qt5')

subdir('Code')
