There is a one-lane bridge on which at most three cars can travel. There is no external 
coordinator and the cars must make their own decision about crossing the bridge. Assume that 
all cars play nicely and want to avoid collision.

Write a program where the threads (cars) access the bridge (shared resource). 

The implementation should be fair in providing access to each waiting car. If there are cars
waiting at both ends, only 3 cars travel from each end in an alternate manner. If there are 
no cars on the other end, cars can travel until a single car shows up at the other end.
