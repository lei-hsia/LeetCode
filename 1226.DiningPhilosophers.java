```
class DiningPhilosophers
{
    private Lock forks[] = new Lock[5];
    private Semaphore semaphore = new Semaphore(4);
    
    public DiningPhilosophers()
    {
        for (int i = 0; i < 5; i++)
            forks[i] = new ReentrantLock();
    }
    
    void pickFork(int id, Runnable pick)
    {
        forks[id].lock();
        pick.run();
    }
    
    void putFork(int id, Runnable put)
    {
        put.run();
        forks[id].unlock();
    }
    
    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException
    {
        int leftFork = philosopher;
        int rightFork = (philosopher + 4) % 5;
        
        semaphore.acquire();
        
        pickFork(leftFork, pickLeftFork);
        pickFork(rightFork, pickRightFork);
        eat.run();
        putFork(rightFork, putRightFork);
        putFork(leftFork, putLeftFork);
        
        semaphore.release();
    }
}
```