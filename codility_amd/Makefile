APP ?= amd.main
src := codility_amd
build := build
bin := bin
app := $(bin)/$(APP)

# Searches for cpp, c and assembly files.
# In case there are assembly files, just add "-or -name *.s" 
sources := $(shell find $(src) -name *.cpp -or -name *.c)
objects := $(sources:%=$(build)/%.o)
deps := $(objects:.o=.d)

# Objects without the main method.
objs := $(filter-out %.main.cpp.o %.test.cpp.o,$(objects))
app_objs := $(filter %$(APP).cpp.o,$(objects)) $(objs)
deps := $(objects:.o=.d)

MKDIR_P ?= mkdir -p
CXX ?= g++
LIB ?= -lpthread -static-libasan -static-libubsan -static-liblsan

# Warning Options
# Wpedantic: issue all the warnings demanded by strict ISO C and ISO C++.
warnings := -Wall -Wextra -Wpedantic -Wsuggest-override -Wconversion \
-Wsign-conversion -Wuseless-cast -Wshadow -Wvla -Wnull-dereference -Wswitch-enum \
-Wduplicated-cond -Wduplicated-branches \
-Wimplicit-fallthrough

# Sanitizers improve application security.
# 
# Make sure to specify -fsanitize=undefined,address,leak to BOTH the compile and
# the link line. Typically, sanitizers cannot be combined with each other — the
# only supported combination is Asan+UBsan+Lsan (address,undefined,leak).
sanitizers := -fsanitize=address,undefined,leak

# debugging related info
debug := -fno-omit-frame-pointer -fvar-tracking-assignments -rdynamic

# -D_GLIBCXX_DEBUG => switches out the std lib with a safe one that does bounds
#  checking on everything (even overloaded [] operators)
override CPPFLAGS += -I. -MMD -D_GLIBCXX_DEBUG

# it is important to use at least optimization level -O1 because it appears that
# some errors are not detected without optimization. If a stack trace is not
# needed, -g and -fno-omit-frame-pointer can be skipped.
override CXXFLAGS += -std=c++14 -g -O1 $(warnings) $(sanitizers) $(debug)

.PHONY: all

all: $(app)

# Application's executable rule.
$(app): build_msg $(app_objs) | $(bin)
	@$(RM) $@
	$(CXX) $(app_objs) -o $@ $(sanitizers) $(LIB) $(LDFLAGS)
	@ls -lh $@

# C++ sources to objects
$(build)/%.cpp.o: %.cpp 
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Makes bin directory
$(bin):
	$(MKDIR_P) $@

.PHONY: build_msg clean
build_msg:
	@echo "Building "$(APP)
clean:
	$(RM) -r $(build)

# Avoids inclusion when cleaning.
ifneq ($(MAKECMDGOALS),clean)
  -include $(deps)
endif
