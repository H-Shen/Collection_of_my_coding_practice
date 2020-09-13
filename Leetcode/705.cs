using System.Collections;

public class MyHashSet
{
    private int MAX_LENGTH = 1000005;
    private BitArray mBitArray;
    /** Initialize your data structure here. */
    public MyHashSet()
    {
        mBitArray = new BitArray(MAX_LENGTH);
    }

    public void Add(int key)
    {
        mBitArray[key] = true;
    }

    public void Remove(int key)
    {
        mBitArray[key] = false;
    }

    /** Returns true if this set contains the specified element */
    public bool Contains(int key)
    {
        return mBitArray[key];
    }
}