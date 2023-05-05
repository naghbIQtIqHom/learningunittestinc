.PHONY: all build test clean run

CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c17
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=gnu++2b
LDFLAGS=
LDFLAGS_UNITTEST= -lCatch2Main -lCatch2

SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# デフォルトターゲットは最初に持ってこないといけない
all: build test


TARGET=$(BIN_DIR)/hello

$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^


# main()を無理にユニットテスト可能にするための記述
TEST_DIR=test
TEST_FILES=$(wildcard $(TEST_DIR)/*.cpp)
OBJ_UNITTEST_DIR=obj/obj_unittest
OBJ_UNITTEST_FILES=$(patsubst $(TEST_DIR)/%.cpp,$(OBJ_UNITTEST_DIR)/%.o,$(TEST_FILES))
OBJ_UNITTEST_SRC_DIR=obj/obj_unittest_src
OBJ_UNITTEST_SRC_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_UNITTEST_SRC_DIR)/%.o,$(SRC_FILES))

UNITTEST_TARGET=$(BIN_DIR)/test_hello

$(OBJ_UNITTEST_SRC_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_UNITTEST_SRC_DIR)
	$(CC) $(CFLAGS) -DMAIN_FOR_UNITTEST -c -o $@ $<

$(OBJ_UNITTEST_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_UNITTEST_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $^


$(UNITTEST_TARGET): $(OBJ_UNITTEST_FILES) $(OBJ_UNITTEST_SRC_FILES) | $(OBJ_UNITTEST_DIR) $(OBJ_UNITTEST_SRC_DIR) $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS_UNITTEST)



build: $(TARGET) $(UNITTEST_TARGET)

test: $(UNITTEST_TARGET)
	$(UNITTEST_TARGET)

run: $(TARGET)
	- $(TARGET)

$(OBJ_DIR) $(BIN_DIR) $(OBJ_UNITTEST_DIR) $(OBJ_UNITTEST_SRC_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(OBJ_UNITTEST_DIR) $(OBJ_UNITTEST_SRC_DIR)

