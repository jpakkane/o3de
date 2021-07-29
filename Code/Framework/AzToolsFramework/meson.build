aztoolsframework_files = []

subdir('AzToolsFramework')
subdir('Platform')

aztoolsframework_lib = static_library('AzToolsFramework',
    aztoolsframework_files,
    include_directories: ['AzToolsFramework'],
    dependencies: [azframework_dep, azcore_dep, qt5_dep, rapidxml_dep, rapidjson_dep, lua_dep],
    )

aztoolsframework_dep = declare_dependency(include_directories: '.')
