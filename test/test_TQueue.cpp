#include "TQueue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length) {
	ASSERT_NO_THROW(TQueue<int> q(10));
}

TEST(TQueue, cant_create_too_large_queue) {
	ASSERT_NO_THROW(TQueue<int> q(100));
}

TEST(TQueue, throws_when_create_queue_with_negative_length) {
	ASSERT_ANY_THROW(TQueue<int> q(-15));
}

TEST(TQueue, can_copy) {
	TQueue<int> temp(15);
	ASSERT_NO_THROW(TQueue<int> q2(temp));
}

TEST(TQueue, knows_if_empty1) {
	TQueue<int> q(3);
	EXPECT_EQ(true, q.isEmpty());
}

TEST(TQueue, can_push_and_get_count) {
	TQueue<int> q(2);
	int num = 1;
	q.push(num);
	EXPECT_EQ(1, q.getCount());
}

TEST(TQueue, can_pull_and_get_count) {
	TQueue<int> q(1);
	int num = 1;
	q.push(num);
	q.pull();
	EXPECT_EQ(0, q.getCount());
}

TEST(TQueue, can_get_size) {
	TQueue<int> q(5);
	EXPECT_EQ(5, q.getSize());
}

TEST(TQueue, can_assign_queue_to_itself) {
	TQueue<int> q(11);
	ASSERT_NO_THROW(q = q);
}

TEST(TQueue, ring_pull) {
	TQueue<int> q(2);
	int num = 1;
	q.push(num);
	q.push(num);
	q.pull();
	EXPECT_EQ(1, q.getStart());
}

TEST(TQueue, ring_push) {
	TQueue<int> q(2);
	int num = 1;
	q.push(num);
	q.push(num);
	q.pull();
	q.push(num);
	EXPECT_EQ(1, q.getEnd());
}

TEST(TQueue, checks_if_full) {
	TQueue<int> q(1);
	int num = 1;
	q.push(num);
	EXPECT_EQ(1, q.isFull());
}

TEST(TQueue, checks_if_empty) {
	TQueue<int> q(1);
	EXPECT_EQ(1, q.isEmpty());
}
