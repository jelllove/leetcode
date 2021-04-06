#include "../../include/public.h"

template<class T>
class CMyHeap
{

public:
    CMyHeap() : m_size(0)
    {
        //初始化大小为0
    }

    bool empty()
    {
        return (m_size == 0);
    }

    T peek()
    {
        //取最top的那个
        if (m_size == 0)
        {
            throw runtime_error("No element");
        }
        else
        {
            return m_data[0];
        }
    }

    void push(T data)
    {
        //使用m_size来控制大小，这样的话，就不需要vector一直进行size的变化了
        if (m_data.size() < (m_size + 1))
        {
            //如果当前的size不够的话，那还是要push_back的 
            m_data.push_back(data);
        }
        else
        {
            m_data[m_size] = data;
        }

        ++m_size;

        //将新的元素放到最后面
        int childIndex = m_size - 1;
        
        while (childIndex > 0)
        {
            //然后找到它的父结点
            int parentIndex = (childIndex - 1) / 2;
            //这个是一个min heap，所以父结点小于子结点
            if (m_data[parentIndex] < m_data[childIndex])
            {
                //如果父结点的值已经比它小了，那就不用看了，直接退出
                break;
            }
            else
            {
                //否则就让它和父结点交换，然后index改成父结点的
                swap(m_data[parentIndex], m_data[childIndex]);
                childIndex = parentIndex;
            }
        }
    }

    T pop()
    {
        if (m_size == 0)
        {
            throw runtime_error("No element");
        }

        //如果就一个元素了，直接pop出来
        if (m_size == 1)
        {
            m_size = 0;
            return m_data[0];
        }

        //把第一个和最后一个元素交换，然后size减1
        swap(m_data[0], m_data[m_size - 1]);
        --m_size;

        //刚刚从最后一个元素变成了第一个元素
        int parentIndex = 0;

        //接下来要以这个元素为起点，然后一个个往下去与它的两个子结点比较
        //找到其中比较小的那个，与它交换，然后再往下比较，一直到父结点比两个子结点都要小为止
        while (parentIndex < m_size)
        {
            //找出左右结点的index
            int leftIndex = parentIndex * 2 + 1;
            int rightIndex = parentIndex * 2 + 2;

            //因为堆中，如果有子结点的话，一定是有左子结，所以如果左子结点都没有，那就不用看了
            if (leftIndex >= m_size)
            {
                break;
            }
            
            //看看有没有右子结点
            if (rightIndex >= m_size)
            {
                //没有右子结点，就只比较左子结点
                if (m_data[parentIndex] > m_data[leftIndex])
                {
                    swap(m_data[leftIndex], m_data[parentIndex]);
                    parentIndex = leftIndex;
                }
                else
                {
                    break;
                }
            }
            else
            {
                //有左有右的情况下，看看父结点是否都小于它们，如果是的话，那就不用比了
                if (m_data[parentIndex] <= min(m_data[leftIndex], m_data[rightIndex]))
                {
                    break;
                }

                //找出左右中小的那个，然后与父结点交换
                if (m_data[leftIndex] < m_data[rightIndex])
                {
                    swap(m_data[leftIndex], m_data[parentIndex]);
                    parentIndex = leftIndex;
                }
                else
                {
                    swap(m_data[rightIndex], m_data[parentIndex]);
                    parentIndex = rightIndex;
                }
            }
        }
        //返回刚从第一个交换过来的那个最后的元素
        return m_data[m_size];
    }

private:
    vector<T> m_data;
    size_t m_size;
};


int main()
{

    CMyHeap<int> heap;

    heap.push(7);
    heap.push(2);
    heap.push(3);
    heap.push(9);
    heap.push(1);
    heap.push(4);

    while (!heap.empty())
    {
        cout<<"Peek:"<<heap.peek()<<endl;
        cout<<heap.pop()<<endl;
    }

    return 0;
}