// 饿汉式单例
class Singleton1{
    private static Singleton instance = new Singleton();
    private Singleton(){}
    public static Singleton getInstance() { return sin; }
}

// 懒汉式单例（通过双重锁机制实现线程安全）
class Singleton2{
    private static Singleton instance;
    private Singleton(){}
    public static Singleton getInstance() {
        if(instance == NULL){
            synchronized(Singleton.class) {
                if(instance == NULL){
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }
}