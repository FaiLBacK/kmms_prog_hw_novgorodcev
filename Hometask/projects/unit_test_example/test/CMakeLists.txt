set(SOURCES
	test_bubble.cpp
)

add_executable(test_bubble ${SOURCES})

target_include_directories(test_bubble PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/../src
)

target_link_libraries(test_bubble
	gtest_main
	gmock_main
	${LIBRARY}
)

add_test(test_bubble test_bubble)