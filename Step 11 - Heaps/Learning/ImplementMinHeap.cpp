class Solution{
    public:
        int capacity = 100000;
        int size;
        int* arr;

        void initializeHeap(){
            size = 0;
            arr = new int[capacity];
        }

        int parent(int i){
            return (i-1)/2;
        }

        int left(int i){
            return 2*i + 1;
        }

        int right(int i){
            return 2*i + 2;
        }

        void insert(int key){
            if (size == capacity) return;

            arr[size] = key;
            int k = size;
            size++;

            while(k != 0 && arr[parent(k)] > arr[k]){
                swap(arr[parent(k)], arr[k]);
                k = parent(k);
            }
        }

        void heapify(int index){
            int li = left(index);
            int ri = right(index);

            int smallest = index;

            if (li < size && arr[smallest] > arr[li]){
                smallest = li;
            }
            if (ri < size && arr[smallest] > arr[ri]){
                smallest = ri;
            }
            if (index != smallest){
                swap(arr[index] , arr[smallest]);
                heapify(smallest);
            }
        }

        void changeKey(int index, int new_val){
            if (size <= index) return;

            arr[index] = new_val;
            
            if (index != 0 && arr[parent(index)] > arr[index]){
                while(index != 0 && arr[parent(index)] > arr[index]){
                    swap(arr[parent(index)], arr[index]);
                    index = parent(index);
                }
            }
            else{
                heapify(index);
            }
        }

        void extractMin(){
            if (size == 0) return;
            if (size == 1){
                size--;
                return;
            }

            arr[0] = arr[size-1];
            size--;

            heapify(0); 
        }

        bool isEmpty(){
            return size == 0;
        }

        int getMin(){
            if (size == 0) return -1;
            return arr[0];
        }

        int heapSize(){
            return size;
        }
};