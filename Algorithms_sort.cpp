void bubbleSort(int *array, int size) {         // Função que recebe um vetor e seu tamanho
    int aux;                                    // Variável auxiliar para a troca de posições
    for(int i = 0; i < size; i++) {        
        for(int j = 0; j < size-i-1; j++) {
            if(array[j] > array[j+1]) {         // Se o conteúdo atual é maior que o próximo
                aux = array[j];                 
                array[j] = array[j+1];
                array[j+1] = aux; 
            }
        }
    }
}

void selectionSort(int *array, int size) {      // Função que recebe um vetor e seu tamanho
    int aux;                                    // Variável auxiliar para a troca de posições
    int imin;                                   // Variável de definição do menor termo
    for(int i = 0; i < size-1; i++) {           
        imin = i;                               // Menor valor é o 1º termo do vetor
        for(int j = i+1; j < size; j++){
            if(array[j] < array[imin]){         // Se o conteúdo atual é menor que o 'mínimo'
                aux = array[j];                 
                array[j] = array[imin];
                array[imin] = aux; ;
            }
        }
    }
}

void insertionSort(int *array, int size) {      // Função que recebe um vetor e seu tamanho
   int key;                                     // Variável 'chave' para o menor valor
   int j;                                       // Variável auxiliar para a troca de posições
   for(int i = 1; i<size; i++) {                // Percorre o vetor a partir da 2ª posição
        key = array[i];                           // Atribui a 'chave' ao valor atual
        j = i;
        while(j > 0 && array[j-1]>key) {          // Percorre o vetor inversamente enquanto for maior que a 'chave'
            array[j] = array[j-1];                 // Atribui o valor atual como o anterior (deslocando para a direita)
            j--;
        }
        array[j] = key;                           // Atribui o menor valor na menor posição
    }
}

int quick(int *array, int start, int size)          // Função que recebe um vetor, início e seu tamanho
{
    int piviot = array[size];                       // Escolhe o pivô
    int pind = start;                               // Escolhe o auxiliar de início
    int i, t;

    for (i = start; i < size; i++) {
        if (array[i] <= piviot) {                   // Se o valor atual for 
            t = array[i];                               // igual ao auxiliar
            array[i] = array[pind];             
            array[pind] = t;
            pind++;
        }
    }

    t = array[size];
    array[size] = array[pind];
    array[pind] = t;

    return pind;                                    // Retorna o auxiliar
}

void quicksort(int* array, int start, int size)     // Função que recebe um vetor, início e seu tamanho
{
    if (start < size) {                             // Se o início for menor que o tamanho
        int pind = quick(array, start, size);       // Chama a função de partição passando os mesmos parâmetros
        quicksort(array, start, pind - 1);          // De maneira recursiva retorna a função QuickSort particionada
        quicksort(array, pind + 1, size);           // Por fim, retorna a função QuickSort com o start na posição seguinte
    }
}

void merge(int *array, int start, int mid, int size) {  // Função que recebe um vetor, início, meio e seu tamanho
    int i, j, k, left, right;
    left = mid - start + 1;                             // Define o tamanho da direita e esquerda dos subvetores
    right = size - mid;
    int larr[left], rarr[right];
    for(i = 0; i < left; i++)                           // Preenche os subvetores
        larr[i] = array[start+i];
    for(j = 0; j < right; j++)
        rarr[j] = array[mid+1+j];
    i = 0; j = 0; k = start;
    while(i < left && j < right) {                      // Retorna os subvetores
        if(larr[i] <= rarr[j]) {                            // para o vetor original
            array[k] = larr[i];
            i++;
        }else{
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i < left) {                                   // Elemento extra do subvetor da esquerda
        array[k] = larr[i];
        i++; k++;
    }
    while(j < right) {                                  // Elemento extra do subvetor da direita
       array[k] = rarr[j];
       j++; k++;
    }
}

void mergeSort(int *array, int start, int size) {       // Função que recebe um vetor, início e seu tamanho
   int mid;                         
   if(start < size) {
        mid = start+(size-start)/2;                     // Define o meio do vetor                                                    
        mergeSort(array, start, mid);                   // Ordena a primeira parte
        mergeSort(array, mid + 1, size);                // Orena a segunda parte
        merge(array, start, mid, size);
    }
}

void shellSort(int *array, int size) {              // Função que recebe um vetor, início e seu tamanho
    int gap, j, k, aux;
    for(gap = size/2; gap > 0; gap = gap / 2) {     // Inicialmente gap = size / 2
        for(j = gap; j < size; j++) {               // Percorrendo da lacuna até o final do vetor
            for(k = j-gap; k >= 0; k -= gap) {
                if(array[k+gap] >= array[k]){       // Se o valor do gap for maior ou igual ao valor atual
                    break;
                }
                else{
                    aux = array[k+gap];                 
                    array[k+gap] = array[k];
                    array[k] = aux;
                }
            }
        }
    }
}

int main (){
    int array[5] = {5,2,1,4,3};
    int size = 5;
    int start = 0;
    bubbleSort(array, size);
    selectionSort(array, size);
    insertionSort(array, size);
    quicksort(array, start, size);
    mergeSort(array, start, size);
    shellSort(array, size);
}

