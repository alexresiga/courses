#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem;
int ret;
int big_array[100];
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int pos = 0;

void print_array(int A[], int size);
void merge_sort(int arr[], int l, int r);

void *serve_client(void* client)
{
    int c = *((int*)client);
    int i;
    int32_t b,n;
    recv(c, &n, 4, 0);
    n = ntohl(n);
    pthread_mutex_lock(&mtx);
    ret++;
    pthread_mutex_unlock(&mtx);
    if(n == 0){
        merge_sort(big_array, 0, pos-1);
        for(i = 1; i <= ret; i++)
            sem_post(&sem);
    }
    for(i=0; i < n; i++){
        recv(c, &b, 4, 0);
        b = ntohl(b);
        pthread_mutex_lock(&mtx);
        big_array[pos] = b;
        pos++;
        pthread_mutex_unlock(&mtx);
    }
    print_array(big_array, pos);
    sem_wait(&sem);
    send(c, &pos, sizeof(int32_t), MSG_CONFIRM);
    for(i = 0; i < pos; i++){
        send(c, &big_array[i], sizeof(int32_t), MSG_CONFIRM);
    close(c);
    free(client);
    return NULL;
} 
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main()
{
    sem_init($sem, 0, 0);
    unsigned int l;
    int s, cnct;
    struct sockaddr_in client, server;  
  
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        fprintf(stderr, "Eroare la creare socket server.\n");
        return 1;
    }
  
    memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_port = htons(4444);
    server.sin_addr.s_addr = INADDR_ANY;
  
    cnct = bind(s, (struct sockaddr *) &server, sizeof(struct sockaddr_in));
    if (cnct < 0) {
        fprintf(stderr, "Eroare la bind. Portul este deja folosit.\n");
        return 1;
    }
  
    listen(s, 5);

    while(1){
        memset(&client, 0, sizeof(client));
        l = sizeof(client);
        int* c = (int*)malloc(sizeof(int));
        *c = accept(s, (struct sockaddr *) &client, &l);
        pthread_t t;
        pthread_create(&t, NULL, serve_client, c);
        pthread_detach(t);
    }
    sem_destroy(&sem);
    return 0;
}
