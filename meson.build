project('o3de', 'c', 'cpp',
   default_options: ['cpp_std=c++17'])

add_project_arguments('-msse4.1', language: 'cpp')
add_project_arguments('-msse4.1', language: 'c')

add_project_arguments('-DAZ_BUILD_CONFIGURATION_TYPE="debug"', language: 'cpp')

rapidjson_dep = dependency('rapidjson')
rapidxml_dep = dependency('rapidxml')
zstd_dep = dependency('libzstd')
lua_dep = dependency('lua')
cityhash_dep = dependency('cityhash')

subdir('Code')
