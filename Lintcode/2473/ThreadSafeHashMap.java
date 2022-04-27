public class ThreadSafeHashMap extends AbstractHashMap {
    // write your code
    
    public ThreadSafeHashMap(int baseSize) {
        super(baseSize);
        // write your code
        
    }
    
    public void put(int key, int value) {
        // modify the following code
        synchronized(this) {
            super.put(key, value);
        }
    }
    
    public int get(int index) {
        // modify the following code
        synchronized(this) {
            return super.get(index);
        }
    }
}