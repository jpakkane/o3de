aznetworking_files = []

subdir('AzNetworking')
subdir('Platform')

aznetworking_lib = static_library('AzNetworking',
  aznetworking_files,
  include_directories: ['Platform/Linux', 'Platform/Common'],
  dependencies: [azcore_dep],
)
