//
// Created by 28943 on 2019/11/6.
//

#ifndef CPLUSPLUS_MYLIST1106_H
#define CPLUSPLUS_MYLIST1106_H


namespace km{
    template <class T>
    class ListNode{
    public:
        T m_val;
        ListNode *m_prev;
        ListNode *m_next;

        ListNode(const T &val = T())://默认构造?
        m_prev(nullptr),
        m_next(nullptr),
        m_val(val){

        }
    };
    template <class T>
    class list{
        ListNode<T> *m_head;

        void creatHead(){
            m_head = new ListNode<T>;
            m_head->m_next = m_head->m_prev = m_head;
        }

    public:
        class iterator{//构建迭代器类, 重载必要的操作符
        public:
            ListNode<T> *m_pos;

            iterator(ListNode<T> *val = nullptr):
            m_pos(val){

            }

            T& operator*() const{
                return m_pos->m_val;
            }

            T& operator->() const{
                return &m_pos->m_val;
            }

            iterator operator++(){
                m_pos = m_pos->m_next;
                return *this;
            }

            iterator operator++(int){
                iterator tmp = *this;
                m_pos = m_pos->m_next;
                return tmp;
            }

            iterator operator--(){
                m_pos = m_pos->m_prev;
                return *this;
            }

            iterator operator--(int){
                iterator tmp = *this;
                m_pos = m_pos->m_prev;
                return tmp;
            }

            bool operator==(const iterator& ci) const {
                return m_pos == ci.m_pos;
            }

            bool operator!=(const iterator& ci) const {
                return m_pos != ci.m_pos;
            }
        };

        list(){
            creatHead();
        }

        list(int n, const T &val = T()){
            creatHead();

            int i;
            for(i = 0; i < n; i++){
                Bush_back(val);
            }
        }

        list(iterator start, iterator finish){
            creatHead();

            Inser(End(), start, finish);
        }

        list(T *start, T *finish){
            creatHead();
            Insert(End(), start, finish);
        }

        list(list<T> &l){
            creatHead();
            Insert(End(), l.Begin(), l.End());
        }

        ~list(){
            Erase(Begin(), End());
            delete m_head;
        }

        void Clear(){
            Erase(Begin(), End());
        }

        void push_back(const T &val){
            Insert(End(), val);
        }

        void Push_pront(const T &val){
            Insert(Begin(), val);
        }

        void Pop_back(const T &val){
            Erase(--End());
        }

        void Pop_front(){
            Erase(Begin());
        }

        iterator Insert(iterator pos, const T &val) {
            ListNode<T> *cur = new ListNode<T>;
            ListNode<T> *npos = pos.m_pos;

            cur->m_val = val;

            cur->m_prev = npos->m_prev;
            cur->m_prev->m_next = cur;

            cur->m_next = npos;
            npos->m_prev = cur;

            return cur;
        }

        iterator Insert(iterator pos, T* start, T *finish){
            T *tmp;
            iterator tmpit = --pos;//pos放到插入前的前一个元素
            pos++;

            for(tmp = start; tmp != finish; tmp++){
                Insert(pos, *tmp);
            }

            return ++tmpit;//插入后恢复
        }

        iterator Insert(iterator pos, iterator start, iterator end){
            iterator tmp;
            iterator tmpit = --pos;
            pos++;

            for(tmp = start; tmp != end; tmp++){
                Insert(pos, *tmp);
            }

            return ++tmpit;
        }

        iterator Erase(iterator pos){
            ListNode<T> *cur = pos.m_pos;
            ListNode<T> *nextpos = cur->m_next;

            cur->m_next->m_prev = cur->m_prev;
            cur->m_prev->m_next = cur->m_next;
            delete cur;

            return nextpos;
        }

        iterator Begin(){
            return m_head->m_next;
        }

        iterator End(){
            return m_head;
        }

    };
};


#endif //CPLUSPLUS_MYLIST1106_H
