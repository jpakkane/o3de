azcore_files = []

subdir('AzCore')
subdir('Platform')

azcore_lib = static_library('AzCore',
    azcore_files,
    include_directories: 'Platform/Linux',
    dependencies: [rapidjson_dep,
        rapidxml_dep,
        zstd_dep,
        lua_dep,
        cityhash_dep,
        thread_dep,
        dl_dep,
        zlib_dep,
        unwind_dep]
    )

azcore_dep = declare_dependency(include_directories: ['.', 'Platform/Linux'],
      link_with: azcore_lib)

