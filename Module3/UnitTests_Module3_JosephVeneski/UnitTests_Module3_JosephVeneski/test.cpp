// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    // is the collection still empty?
    // if not empty, what must the size be?
    ASSERT_FALSE(collection->empty()); // make sure the collection is not empty
    ASSERT_EQ(collection->size(), 1); // size should now be 1
    
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // verify the collection is empty and size is 0 to start
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    add_entries(5);

    // verify that collection is not empty and size is now 5
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxSizeGreaterOrEqualToSizeForVariousEntries) {
    // verify for 0 entries
    ASSERT_TRUE(collection->empty());
    ASSERT_LE(collection->size(), collection->max_size());

    // verify for 1 entry
    add_entries(1);
    ASSERT_EQ(collection->size(), 1);
    ASSERT_LE(collection->size(), collection->max_size());

    // reset collection for next part of test (tests should be isolated)
    collection->clear();

    // verify for 5 entries
    add_entries(5);
    ASSERT_EQ(collection->size(), 5);
    ASSERT_LE(collection->size(), collection->max_size());

    // reseet collection one more time (tests should be isolated)
    collection->clear();

    // verify for 10 entries
    add_entries(10);
    ASSERT_EQ(collection->size(), 10);
    ASSERT_LE(collection->size(), collection->max_size());
}
// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CapacityGreaterOrEqualToVariousEntries) {
    // verify for 0 entries
    ASSERT_TRUE(collection->empty());
    ASSERT_GE(collection->capacity(), collection->size());

    // verify for 1 entry
    add_entries(1);
    ASSERT_EQ(collection->size(), 1);
    ASSERT_GE(collection->capacity(), collection->size());

    // reset collection for next part of test (tests should be isolated)
    collection->clear();

    // verify for 5 entries
    add_entries(5);
    ASSERT_EQ(collection->size(), 5);
    ASSERT_GE(collection->capacity(), collection->size());

    // reset collection one more time (tests should be isolated)
    collection->clear();

    // verify for 10 entries
    add_entries(10);
    ASSERT_EQ(collection->size(), 10);
    ASSERT_GE(collection->capacity(), collection->size());
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, ResizingIncreasesCollection) {
    // verify the collection is empty to begin
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // resize to increase size by 5
    collection->resize(5);

    // verify the collection is no longer empty and size is 5
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 5);

    // all entries should be initialized to zero by default
    for (size_t i = 0; i < collection->size(); ++i) {
        ASSERT_EQ((*collection)[i], 0) << "Element at index " << i << " is not initialized to 0";
    }
}
// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, ResizingDecreasesCollection) {
    // verify the collection is empty to begin 
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // add 10 entries to populate collection
    add_entries(10);

    // verify collection is not empty and size is exactly 10
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 10);

    // resize to decrease collection
    collection->resize(5);

    // verify the collection correctly resized to 5 entries
    ASSERT_EQ(collection->size(), 5);
    
    // verify that capacity is still greater than or equal to size
    ASSERT_GE(collection->capacity(), collection->size());
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, ResizingCollectionToZero) {
    // verify the collection is empty to begin 
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // add 10 entries to populate collection
    add_entries(10);

    // verify collection is not empty and size is exactly 10
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 10);

    // resize to 0
    collection->resize(0);

    // verify the collection is now empty and hase zero entries
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, ClearErasesCollection) {
    // verify the collection is empty to begin 
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // add 7 entries to populate collection
    add_entries(7);

    // verify collection is not empty and size is exactly 7
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 7);

    // clear collection
    collection->clear();

    // verify that the collection has been erased and size is now 0
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, EraseFromBeginToEndErasesCollection) {
    // verify the collection is empty to begin 
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // add 4 entries to populate collection
    add_entries(4);

    // verify collection is not empty and size is exactly 4
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 4);

    // erase collection
    collection->erase(collection->begin(), collection->end());

    // verify collection has been completely erased and size is now 0
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, ReserveIncreasesCapacityNotSize) {
    // verify the collection is empty to begin 
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // add 3 entries to populate collection
    add_entries(3);

    // verify collection is not empty and size/capacity is exactly 3
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 3);
    ASSERT_EQ(collection->capacity(), 3);

    // increase capacity from 3 to 5
    collection->reserve(5);

    // verify that size is still 3, and capacity is now 5
    ASSERT_EQ(collection->size(), 3);
    ASSERT_EQ(collection->capacity(), 5);
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, ThrowsExceptionWhenAccessingOutOfBounds) {
    // verify the collection is empty to begin
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // add 4 entries
    add_entries(4); // valid indices are 0, 1, 2, 3

    // verify accessing a valid index does not throw exception
    EXPECT_NO_THROW(collection->at(0)); // this should be a valid access

    // verify accessing out-of-bounds throws a out-of-range exception
    EXPECT_THROW(collection->at(4), std::out_of_range);
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

// Ensures an exception is thrown when attempting to set the capacity 
// to a negative number
// This is a negative test
TEST_F(CollectionTest, ThrowsExceptionSettingCapacityToNegative) {
    // verify the collection is empty to begin 
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // add 9 entries to populate collection
    add_entries(9);

    // verify collection is not empty and size/capacity is exactly 9
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 9);
    ASSERT_EQ(collection->capacity(), 9);

    // throw an exception when attempting to set capacity to -3
    ASSERT_THROW(collection->reserve(-3), std::length_error);
}

// this test verifies that popping back the collection
// results in size being decreased 
TEST_F(CollectionTest, PoppingCollectionDecreasesSize) {
    // verify the collection is empty to begin
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    // add 5 entries to populate the collection
    add_entries(5);

    // verify the colection is not empty and the size is 5
    ASSERT_FALSE(collection->empty());
    ASSERT_EQ(collection->size(), 5);

    // remove an element from the collection 
    collection->pop_back();

    // verify the collection size is now 4
    ASSERT_EQ(collection->size(), 4);
}