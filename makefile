
output_dir := ./bin
output_file := $(output_dir)/test
output_file_clang := $(output_file)_clang

source_dir := ./src
source_files := $(shell echo $(source_dir)/*)

header_dir := ./include
header_files := $(shell echo $(header_dir)/*)

test_dir := ./test
test_files := $(shell echo $(test_dir)/*)

CPPFLAGS := -Iinclude

test: $(output_file)
	$(output_file)

$(output_file): $(source_files) $(header_files) $(test_files)
	g++ $(source_files) $(test_files) -o $(output_file) $(CPPFLAGS)

test-clang: $(output_file_clang)
	$(output_file_clang)

$(output_file_clang): $(source_files) $(header_files) $(test_files)
	clang++ $(source_files) $(test_files) -o $(output_file_clang) $(CPPFLAGS)

format:
	clang-format -i $(source_files) $(header_files) $(test_files)

clean:
	rm $(output_dir)/*

