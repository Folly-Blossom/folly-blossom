#ifndef FOLLY_BLOSSOM_PIXEL_HPP
#define FOLLY_BLOSSOM_PIXEL_HPP

#include <cstdint>

namespace Folly {
    struct RGBColor {
        uint8_t red, green, blue;
    } typedef Color, RGB;

    class Pixel {
    public:
        Pixel(float x, float y, bool isTransparent) {
            this -> x = x;

            this -> y = y;

            this -> colorValue = nullptr;

            this -> isTransparent = isTransparent;
        }

        Pixel(float x, float y, Color *colorValue, bool isTransparent) {
            this -> x = x;

            this -> y = y;

            this -> colorValue = colorValue;

            this -> isTransparent = isTransparent;
        }

        ~Pixel() {
            new Pixel(this -> x, this -> y, true);

            delete (this -> colorValue);
        }

        Color *colorValue {};

        bool isTransparent;

        void SetTransparency(bool transparency) { this -> isTransparent = transparency; }

        void SetCoordinates(float xCoordinate, float yCoordinate) { this -> x = xCoordinate; this -> y = yCoordinate; }

        void FlipHorizontially() { this -> y = -y; }

        void FlipVertically() { this -> x = -x; }

        #pragma clang diagnostic push

        #pragma ide diagnostic ignored "readability-make-member-function-const"

        Color SetColor(Color *color) { return *(this -> colorValue = color); }

        #pragma clang diagnostic pop

        void Rescale(float scaleFactor) { this -> x = x * scaleFactor; this -> y = y * scaleFactor; }

    protected:


    private:
        float x, y;
    };

    template<class T>
    class TreeNode {
    private:
        struct HeapNode {
            T data;
            unsigned int frequency;
            struct HeapNode *leftChild, *rightChild;
        };

        struct Heap {
            unsigned int size;
            unsigned int capacity;
            struct HeapNode **nodes;
        };

        std::unique_ptr<HeapNode> CreateNode(T data, unsigned int frequency) {
            std::unique_ptr<HeapNode> node = new HeapNode;

            node = malloc(static_cast<size_t>(sizeof(data)) + static_cast<size_t>(sizeof(HeapNode)));

            node -> leftChild = node -> rightChild = NULL;

            node -> data = data;

            node -> frequency = frequency;

            return node;
        }

        std::unique_ptr<Heap> CreateHeap(unsigned int capacity) {
            std::unique_ptr<Heap> *heap = static_cast<Heap*>(malloc(sizeof(Heap)));

            heap -> size = 0;

            heap -> capacity = capacity;

            heap -> nodes = (malloc(sizeof(heap -> capacity));

            return heap;
        }

        void SwapNode(HeapNode **first, HeapNode **second) {
            HeapNode *t = *first;

            *first = *second;

            *second = t;
        }

        void InitializeHeap(Heap *heap, int index) {
            int smallest = index;

            int left = (2 * index) + 1;

            int right = (2 * index) + 2;

            if ((left < heap -> size) &&
            (heap -> nodes[left] -> frequency < heap -> nodes[smallest] -> frequency)) {
                smallest = left;
            }

            if ((right < heap -> size) &&
            (heap -> nodes[right] -> frequency < heap -> nodes[smallest] -> frequency)) {
                smallest = right;
            }

            if (smallest != index) {
                SwapNode(&heap -> nodes[smallest], &heap -> nodes[index]);

                InitializeHeap(heap, smallest);
            }
        }

        int IsSizeOne(Heap *heap) {
            return (heap -> size == 1);
        }

        std::unique_ptr<HeapNode> ExtractHeapNode(Heap *heap) {
            std::unique_ptr<HeapNode> node = heap -> nodes[0];

            heap -> nodes[0] = heap -> nodes[heap -> size - 1];

            --heap -> size;

            InitializeHeap(heap, 0);

            return node;
        }

        void InsertHeap(Heap *heap, HeapNode *node) {
            ++heap -> size;

            int i = heap -> size - 1;

            while (i && node -> frequency < heap -> nodes[(i - 1) / 2] -> frequency) {
                heap -> nodes[i] = heap -> nodes[(i - 1) / 2];

                i = (i - 1) / 2;
            }
        }

        void BuildHeap(Heap *heap) {
            int n = heap -> size - 1;

            for (int i = (n - 1) / 2; i >= 0; --i) {
                InitializeHeap(heap, i);
            }
        }

        int IsNodeALeaf(HeapNode *rootNode) {
            return !(rootNode -> leftChild) && !(rootNode -> rightChild);
        }

        std::unique_ptr<Heap> CreateAndConstructHeap(char data[], int frequency[], int size) {
            std::unique_ptr<Heap> heap = CreateHeap(size);

            for (int i  = 0; i < size; ++i) {
                heap -> nodes[i] = CreateNode(data[i], frequency[i]);
            }

            heap -> size  = size;

            BuildHeap(heap);

            return heap;
        }

        std::unique_ptr<HeapNode> CreateNodeTree(T data[], int frequency[], int size) {
            std::unique_ptr<HeapNode> left, right, top;

            std::unique_ptr<Heap> heap = CreateAndConstructHeap(data, frequency, size);

            while (!IsSizeOne(heap)) {
                left = ExtractHeapNode(heap);

                right = ExtractHeapNode(heap);

                // 'data[-1]' Will be used as a special values for internal nodes.
                top = CreateNode(data[-1], left -> frequency + right -> frequency);

                top -> leftChild = left;

                top -> rightChild = right;

                InsertHeap(heap, top);
            }

            return ExtractHeapNode(heap);
        }

        void PrintCodesToTree(HeapNode *rootNode, int nodes[], int topNode) {
            if (rootNode -> leftChild) {
                nodes[topNode] = 0;

                PrintCodesToTree(rootNode -> leftChild, nodes, topNode + 1);
            }

            if (rootNode -> rightChild) {
                nodes[topNode] = 1;

                PrintCodesToTree(rootNode -> rightChild, nodes, topNode + 1);
            }
        }
    };

    struct Dimensions {
        Pixel height[1920], width[1080];
    };
}

#endif /*FOLLY_BLOSSOM_PIXEL_HPP*/
