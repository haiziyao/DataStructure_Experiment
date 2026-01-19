//
// Created by 17542 on 2025/11/4.
//

#ifndef DATASTRUCTURE_HOMEWORK_WORK11_H
#define DATASTRUCTURE_HOMEWORK_WORK11_H

#include <cstdint>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <queue>
namespace question11{
using namespace  std;

    class BitReader {
    private:
        const vector<uint8_t> data;
        vector<uint8_t>::size_type byteIndex;
        int bitIndex;
    public:
        explicit BitReader(const vector<uint8_t>& bytes);
        bool hasNext() const ;
        char readBit();
    };

    class BitWriter {
    private:
        ostream& output;
        uint8_t currentByte;
        int bitIndex;

    public:
        explicit BitWriter(ostream& os);
        void writeBit(char bit);
        void writeCode(const string& code);
        void flush();
    };


     class HuffmanNode {
     public:
         char character;
         int frequency;
         shared_ptr<HuffmanNode> left;
         shared_ptr<HuffmanNode> right;

         HuffmanNode(int frequency, shared_ptr<HuffmanNode> left, shared_ptr<HuffmanNode> right)
        : character('\0'), frequency(frequency), left(left), right(right) {
         }

         // 叶子节点的构造函数
         HuffmanNode(char character, int frequency)
             : character(character), frequency(frequency), left(nullptr), right(nullptr) {
         }

         bool isLeaf() const;
         bool operator>(const HuffmanNode &other) const;
     };
    //自定义比较器
    class HuffmanNodeComparator {
    public:
        bool operator()(const shared_ptr<HuffmanNode> &a,const shared_ptr<HuffmanNode> &b) {
            return a->frequency>b->frequency;
        }
    };

    class HuffmanCoderExample {
    public:
        static void decompressFromSingleFile(const string &singleFilepath, const string &decompressedFilepath);
        static void compressToSingleFile(const string &inputFilepath, const string &singleFilepath);
        static void compress(const string &inputFilepath,const string &compressedFilepath,const string &codeTableFilepath);
        static void decompress(const string &compressedFilepath, const string &codeTableFilepath,const string &decompressedFilepath);
    private:
        static shared_ptr<HuffmanNode> buildHuffmanTree(const map<char, int> &frequencyMap);
        static void generateCodes(shared_ptr<HuffmanNode> root, const string &path,map<char, string> &huffmanCodes);
        static void writeCodeTable(const string &filePath, const map<char, string> &huffmanCodes,long totalChars) ;
        static long readCodeTable(const string &filePath, map<string, char> &codeToCharMap);
    };



    void work(int);
}
#endif //DATASTRUCTURE_HOMEWORK_WORK11_H