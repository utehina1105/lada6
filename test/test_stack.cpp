#include "TStack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length) {
  ASSERT_NO_THROW(TStack<int> s(5));
}

TEST(TStack, throws_when_create_stack_with_negative_length) {
  ASSERT_ANY_THROW(TStack<int> s(-10));
}

TEST(TStack, can_copy) {
  TStack<int> s(10);
  ASSERT_NO_THROW(TStack<int> copy(s));
}

TEST(TStack, can_get_size) {
  TStack<int> s(5);
  EXPECT_EQ(5, s.getSize());
}

TEST(TStack, can_push_and_get_count) {
  TStack<int> s(5);
  int num = 1;
  s.push(num);
  EXPECT_EQ(1, s.getCount());
}

TEST(TStack, can_pull_and_get_count) {  
  TStack<int> s(1);
  int num = 1;
  s.push(num);
  s.pull();
  EXPECT_EQ(0, s.getCount());
}

TEST(TStack, checks_if_full) {
  TStack<int> s(1);
  int num = 1;
  s.push(num);
  EXPECT_EQ(1, s.isFull());
}

TEST(TStack, checks_if_empty) {
  TStack<int> s(1);
  EXPECT_EQ(1, s.isEmpty());
}