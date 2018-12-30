
/*
Binary Search (lower_bound and upper bound)

[1] usage
[1.a] it = lower_bound(first, last, value) satisfying: *(it-1) < value <= *it
[1.b] it = upper_bound(first, last, value) satisfying: *(it-1) <= value < *it
[1.c] if we want it satisfying : *it <= value < *(it+1). For example, LC 911.Online Election, we can get it by:
      it = upper_bound(first, last, value) - 1

[2] algo steps:
[2.1] while loop invariant: first <= it <= last
[2.2] each loop will remove half range either by setting first = ++mid or last = mid
[2.3] a for lower bound, if we found any *mid < value then ++mid  <= it  
[2.3] b for upper bound, if we found any *mid <= value then ++mid  <= it
[2.4] then we could set first = ++mid (!= first) else last = mid (!=mid)
[2.4] until first == last then we found it: first == it == last.

*/



template<typename ForwardIterator, typename T>
ForwardIterator
lower_bound (ForwardIterator first, ForwardIterator last, T value)
{
//  loop invariant: first <= it <= last
    while (first != last) {
        auto mid = next(first, distance(first, last) / 2);
        if (*mid < value)     // mid < it
            first = ++mid;    // first <= it
        else // *mid >= value // it <= mid
            last = mid;       // it <= last
    }
    return first;
}


template<typename ForwardIterator, typename T>
ForwardIterator
upper_bound(ForwardIterator first, ForwardIterator last, T value)
{
//  loop invariant: first <= it <= last    
    while (first != last) {
        auto mid = next(first, distance(first, last) / 2);
        if (*mid <= value)     // mid <= it
            first = ++mid;     // first <= it
        else // *mid > value   // it <= mid
            last = mid;        // it <= last
    }
    return first;
}
