#include <iostream>

using namespace std;


class MinHeap {
private:
    int* Process_ID;
    int* Arrival_Times;
    int* Burst_Times;
    int size;
    int capacity;

    
    void swapValues(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

   
    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && (Burst_Times[left] < Burst_Times[smallest] ||
            (Burst_Times[left] == Burst_Times[smallest] && Arrival_Times[left] < Arrival_Times[smallest]))) {
            smallest = left;
        }

        if (right < size && (Burst_Times[right] < Burst_Times[smallest] ||
            (Burst_Times[right] == Burst_Times[smallest] && Arrival_Times[right] < Arrival_Times[smallest]))) {
            smallest = right;
        }

        if (smallest != i) {
            swapValues(Process_ID[i], Process_ID[smallest]);
            swapValues(Arrival_Times[i], Arrival_Times[smallest]);
            swapValues(Burst_Times[i], Burst_Times[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap(int cap) {
        size = 0;
        capacity = cap;
        Process_ID = new int[cap];
        Arrival_Times = new int[cap];
        Burst_Times = new int[cap];
    }


    void insert(int pid, int at, int bt) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        Process_ID[size] = pid;
        Arrival_Times[size] = at;
        Burst_Times[size] = bt;
        int i = size;
        size++;

    
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (Burst_Times[parent] > Burst_Times[i] ||
                (Burst_Times[parent] == Burst_Times[i] && Arrival_Times[parent] > Arrival_Times[i])) {
                swapValues(Process_ID[i], Process_ID[parent]);
                swapValues(Arrival_Times[i], Arrival_Times[parent]);
                swapValues(Burst_Times[i], Burst_Times[parent]);
                i = parent;
            }
            else {
                break;
            }
        }
    }


    int extractMin(int& at, int& bt) {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int minProcess = Process_ID[0];
        at = Arrival_Times[0];
        bt = Burst_Times[0];

        Process_ID[0] = Process_ID[size - 1];
        Arrival_Times[0] = Arrival_Times[size - 1];
        Burst_Times[0] = Burst_Times[size - 1];
        size--;
        heapify(0);

        return minProcess;
    }

    
    bool isEmpty() {
        return size == 0;
    }
};


void SJFScheduling(int Process_ID[], int Arrival_Times[], int Burst_Times[], int n) {
    MinHeap minHeap(n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Arrival_Times[i] > Arrival_Times[j]) {
               
                int temp;

                temp = Process_ID[i];
                Process_ID[i] = Process_ID[j];
                Process_ID[j] = temp;

                temp = Arrival_Times[i];
                Arrival_Times[i] = Arrival_Times[j];
                Arrival_Times[j] = temp;

                temp = Burst_Times[i];
                Burst_Times[i] = Burst_Times[j];
                Burst_Times[j] = temp;
            }
        }
    }

    int currentTime = 0;
    int index = 0;
    int executionOrder[100], orderIndex = 0;

    while (index < n || !minHeap.isEmpty()) {
        
        while (index < n && Arrival_Times[index] <= currentTime) {
            minHeap.insert(Process_ID[index], Arrival_Times[index], Burst_Times[index]);
            index++;
        }

       
        if (minHeap.isEmpty()) {
            currentTime = Arrival_Times[index];
            continue;
        }

        int pid, at, bt;
        pid = minHeap.extractMin(at, bt);

    
        executionOrder[orderIndex++] = pid;
        currentTime += bt;

        cout << "Process P" << pid << " Executed at time: " << currentTime << endl;
    }

    
    cout << "\nExecution order of processes: ";
    for (int i = 0; i < orderIndex; i++) {
        cout << "P" << executionOrder[i] << " ";
    }
    cout << endl;
}

int main() {
  
    int Process_ID[5] = { 1, 2, 3, 4, 5 };
    int Arrival_Times[5] = { 0, 1, 2, 3, 4 };
    int Burst_Times[5] = { 8, 4, 9, 5, 2 };
    int n = 5; 

    cout << "Shortest Job First (SJF) Scheduling \n" << endl;

    SJFScheduling(Process_ID, Arrival_Times, Burst_Times, n);

    return 0;
}