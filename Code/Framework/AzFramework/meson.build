azframework_files = []

subdir('AzFramework')
subdir('Platform')

azframework_lib = static_library('AzFrameWork',
  azframework_files,
  include_directories: ['Platform/Linux'],
  dependencies: [azcore_dep, lz4_dep, gridmate_dep, rapidjson_dep, rapidxml_dep, md5_dep, lua_dep],
)
