project('o3de', 'c', 'cpp',
   default_options: ['cpp_std=c++17'])

add_project_arguments('-msse4.1', language: 'cpp')
add_project_arguments('-msse4.1', language: 'c')

rapidjson_dep = dependency('rapidjson')
rapidxml_dep = dependency('rapidxml')
zstd_dep = dependency('libzstd')
#lua_dep = dependency('lua')

subdir('Code')
