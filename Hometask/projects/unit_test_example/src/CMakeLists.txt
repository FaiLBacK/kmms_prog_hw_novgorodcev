target_sources(bubble_sort_lib
	PRIVATE
		io.cpp
		sortings.cpp
	PUBLIC
		io.hpp
		sortings.hpp
)

target_include_directories(${LIBRARY} PUBLIC
	"${PROJECTS_SOURCE_DIR}/src"
)

target_include_directories(${LIBRARY} PRIVATE
	"${PROJECTS_SOURCE_DIR}/src"
)