这个题如果只是找出那个不同的值，vector中如果可以是int,也可以是string的话，那使用hash是比较合适的
但是因为它是 vector<int>，所以根据bit操作中的 x^x=0，只要把所有的数进行一个位的异或操作，就最后只剩下那个数了
