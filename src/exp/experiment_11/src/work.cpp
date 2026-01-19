//
// Created by 17542 on 2025/11/4.
//


#include "work.h"
#include <fstream>
#include <iostream>
#include <ostream>

question11::BitReader::BitReader(const vector<uint8_t> &bytes) :data(bytes),bitIndex(0),byteIndex(0){
}

bool question11::BitReader::hasNext() const {
    return byteIndex < data.size() || (byteIndex == data.size() && bitIndex > 0);
}

char question11::BitReader::readBit() {
    if (!hasNext()) {
        throw runtime_error("No more bit to be read!");
    }
    uint8_t currentByte = data[byteIndex];
    int bitValue = (currentByte>>(7-bitIndex)) & 1;

    bitIndex++;
    if (bitIndex == 8) {
        byteIndex++;
        bitIndex = 0;;
    }
    return static_cast<char>('0'+bitValue);
}

question11::BitWriter::BitWriter(ostream &os):output(os),currentByte(0),bitIndex(0){

}

void question11::BitWriter::writeBit(char bit) {
    if (bit!='0'&&bit!='1') {
        throw invalid_argument("Bit is not invalid");
    }
    // 0 不处理
    // 1
    if (bit == '1') {
        currentByte |= static_cast<char>(1u<<(7-bitIndex));

    }
    bitIndex++;
    if(bitIndex==8) {
        output.put(static_cast<char>(currentByte));
        bitIndex = 0;
        currentByte= 0;
    }
}

void question11::BitWriter::writeCode(const string &code) {
    for (auto bit : code) {
        writeBit(bit);
    }
}

void question11::BitWriter::flush() {
    if (bitIndex>0) {
        output.put(static_cast<char>(currentByte));
        currentByte = 0;
        bitIndex = 0;
    }
}

bool question11::HuffmanNode::isLeaf() const {
    return left == nullptr && right==nullptr;
}

bool question11::HuffmanNode::operator>(const HuffmanNode &other) const {
    return this->frequency>other.frequency;
}

void question11::HuffmanCoderExample::compress(const string &inputFilepath, const string &compressedFilepath,
    const string &codeTableFilepath) {
    ifstream inputfile(inputFilepath,ios::binary);
    if (!inputfile.is_open()) {
        throw runtime_error("file is not opened | from HuffmanCoderExample::compress");
    }
    string inputContent((istreambuf_iterator<char>(inputfile)),
                            istreambuf_iterator<char>());
    if (inputContent.empty()) {
        throw runtime_error("nothing in imputContent | from HuffmanCodeExample::compress");
    }
    map<char,int> frenquencyMap;
    for (auto entry:inputContent) {
        frenquencyMap[entry]++;
    }
    auto root = buildHuffmanTree(frenquencyMap);

    map<char, string> huffmanCodes;
    generateCodes(root,"",huffmanCodes);

    writeCodeTable(codeTableFilepath, huffmanCodes, inputContent.length());

    ofstream outfile(compressedFilepath,ios::binary);
    if (!outfile.is_open()) {
        throw runtime_error("outfilepath is not opened | from HuffmanCoderExample::compress");
    }
    BitWriter bitwriter(outfile);
    for (auto entry:inputContent) {
        const string &code = huffmanCodes[entry];
        bitwriter.writeCode(code);
    }
    bitwriter.flush();
    outfile.close();

}

void question11::HuffmanCoderExample::decompress(const string &compressedFilepath, const string &codeTableFilepath,
    const string &decompressedFilepath) {
    //读码表
    map<string,char> codeToCharMap;
    long total_chars = readCodeTable(codeTableFilepath,codeToCharMap);
    if (total_chars==0) {
        throw runtime_error("total_chars is zero | from HuffmanCoderExample::decompress");
    }
    //读压缩文件
    ifstream compressedFile(compressedFilepath,ios::binary);
    if (!compressedFile.is_open()) {
        throw runtime_error("compressedFilepath is not opened | from HuffmanCoderExample::decompress");
    }
    vector<uint8_t> BytesVector;
    BytesVector.assign(istreambuf_iterator<char>(compressedFile),istreambuf_iterator<char>());
    compressedFile.close();


    BitReader bitReader(BytesVector);
    string decompressedContent;
    string currentCode;
    long decodedCharCount = 0;

    while (bitReader.hasNext() && decodedCharCount < total_chars) {
        currentCode += bitReader.readBit();

        if (codeToCharMap.find(currentCode) != codeToCharMap.end()) {
            char decodedChar = codeToCharMap[currentCode];
            decompressedContent += decodedChar;
            decodedCharCount++;
            currentCode.clear();
        }
    }

    ofstream decompressedFile(decompressedFilepath,ios::binary);
    if (!decompressedFile.is_open()) {
        throw runtime_error("decompressedFilepath is not opened | from HuffmanCoderExample::decompress");
    }
    decompressedFile << decompressedContent;
    decompressedFile.close();


}

std::shared_ptr<question11::HuffmanNode> question11::HuffmanCoderExample::buildHuffmanTree(
    const map<char, int> &frequencyMap) {
    priority_queue<shared_ptr<HuffmanNode>,vector<shared_ptr<HuffmanNode>>,HuffmanNodeComparator> pq;
    for (const auto entry: frequencyMap) {
        pq.push(make_shared<HuffmanNode>(entry.first, entry.second));
    }

    //这种情况是为了避免后面生成后面huffman表的前序遍历条件出问题
    if (pq.size()==1) {
        shared_ptr<HuffmanNode> thisNode = pq.top();
        pq.pop();
        return make_shared<HuffmanNode>(thisNode->frequency,thisNode,nullptr);
    }

    while (pq.size()>1) {
        shared_ptr<HuffmanNode> left = pq.top();
        pq.pop();
        shared_ptr<HuffmanNode> right = pq.top();
        pq.pop();
        pq.push(make_shared<HuffmanNode>(left->frequency+right->frequency,left,right));
    }
    return pq.top();
}

void question11::HuffmanCoderExample::generateCodes(shared_ptr<HuffmanNode> root, const string &path,
    map<char, string> &huffmanCodes) {
    if (root==nullptr) return;
    //前序遍历
    if (root->isLeaf()) {
        huffmanCodes[root->character] = path;
        return ;
    }
    generateCodes(root->left,path+'0',huffmanCodes);
    generateCodes(root->right,path+'1',huffmanCodes);

}
//只做一件事情，我们把把HuffmanCode写入filePath
void question11::HuffmanCoderExample::writeCodeTable(const string &filePath, const map<char, string> &huffmanCodes,
    long totalChars) {
    ofstream writer(filePath);
    if (!writer.is_open()) {
        throw runtime_error("file is not opened | from writerCodeTable()");
    }
    writer<<"total_chars="<<totalChars<<'\n';
    for (auto entry:huffmanCodes) {
        writer << static_cast<int>(entry.first) << ":" << entry.second << '\n';
    }
    writer.close();

}

long question11::HuffmanCoderExample::readCodeTable(const string &filePath, map<string, char> &codeToCharMap) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw runtime_error("file is not opened | from readCodeTable()");
    }

    string line;
    if (!getline(file,line)) {
        throw runtime_error("file is null | from readCodeTable()");
    }

    const string prefix = "total_chars=";
    if (line.substr(0,prefix.length())!=prefix) {
        throw runtime_error("prefix is wrong! | from readCodeTable()");
    }
    long totalChars = stol(line.substr(prefix.length()));
    while (getline(file,line)) {
        size_t colon_index = line.find(':');
        if (colon_index!=string::npos&&colon_index<line.length()) {
            int charCode = stoi(line.substr(0,colon_index));
            string code = line.substr(colon_index+1 );
            codeToCharMap[code] = static_cast<char>(charCode);
        }

    }
    file.close();
    return totalChars;
}


void question11::work(int a) {
    // string inputFile = "../sources/input.png";
    // string compressedFile = "../sources/compressed.bin";
    // string codeTableFile = "../sources/compressed.htable";
    // string decompressedFile = "../sources/decompressed.png";
    //
    // if (a) {
    //     HuffmanCoderExample::compress(inputFile, compressedFile, codeTableFile);
    // }else {
    //     // --- 步骤 2: 解压缩文件 ---
    //     HuffmanCoderExample::decompress(compressedFile, codeTableFile, decompressedFile);
    // }

    string inputFile = "../sources/input.png";
    string singleFile = "../sources/merged.bin"; // 单文件
    string decompressedFile = "../sources/decompressed.png";

    if (a) {
        // 压缩到单文件
        HuffmanCoderExample::compressToSingleFile(inputFile, singleFile);
    } else {
        // 从单文件解压
        HuffmanCoderExample::decompressFromSingleFile(singleFile, decompressedFile);
    }

}




void question11::HuffmanCoderExample::compressToSingleFile(const string &inputFilepath, const string &singleFilepath) {
    // 1. 读取输入文件内容
    ifstream inputfile(inputFilepath, ios::binary);
    if (!inputfile.is_open()) {
        throw runtime_error("Input file open failed | compressToSingleFile");
    }
    string inputContent((istreambuf_iterator<char>(inputfile)), istreambuf_iterator<char>());
    if (inputContent.empty()) {
        throw runtime_error("Input content is empty | compressToSingleFile");
    }

    // 2. 计算频率、构建哈夫曼树、生成编码表（复用原有逻辑）
    map<char, int> frequencyMap;
    for (char c : inputContent) frequencyMap[c]++;
    auto root = buildHuffmanTree(frequencyMap);
    map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);
    long totalChars = inputContent.size();

    // 3. 写入单文件：编码表（文本）+ 换行分隔符 + 二进制压缩数据
    ofstream outfile(singleFilepath, ios::binary);
    if (!outfile.is_open()) {
        throw runtime_error("Single file open failed | compressToSingleFile");
    }

    // 3.1 写入编码表（格式同原codeTable，结尾加空行作为分隔）
    outfile << "total_chars=" << totalChars << '\n';
    for (const auto &entry : huffmanCodes) {
        outfile << static_cast<int>(static_cast<uint8_t>(entry.first)) << ":" << entry.second << '\n';
    }
    outfile << '\n'; // 换行分隔符（编码表结束标记）

    // 3.2 写入二进制压缩数据（复用BitWriter）
    BitWriter bitwriter(outfile);
    for (char c : inputContent) {
        bitwriter.writeCode(huffmanCodes[c]);
    }
    bitwriter.flush();
    outfile.close();
}


void question11::HuffmanCoderExample::decompressFromSingleFile(const string &singleFilepath, const string &decompressedFilepath) {
    // 1. 打开单文件
    ifstream singleFile(singleFilepath, ios::binary);
    if (!singleFile.is_open()) {
        throw runtime_error("Single file open failed | decompressFromSingleFile");
    }

    // 2. 读取并解析编码表（到换行分隔符为止）
    map<string, char> codeToCharMap;
    long totalChars = 0;
    string line;
    bool isTableEnd = false;

    // 2.1 解析总字符数
    if (!getline(singleFile, line) || line.substr(0, 12) != "total_chars=") {
        throw runtime_error("Invalid code table format | decompressFromSingleFile");
    }
    totalChars = stol(line.substr(12));

    // 2.2 解析字符-编码映射（直到遇到空行分隔符）
    while (getline(singleFile, line)) {
        if (line.empty()) { // 空行表示编码表结束
            isTableEnd = true;
            break;
        }
        size_t colonPos = line.find(':');
        if (colonPos == string::npos) continue;
        int charCode = stoi(line.substr(0, colonPos));
        string code = line.substr(colonPos + 1);
        codeToCharMap[code] = static_cast<char>(charCode);
    }
    if (!isTableEnd) {
        throw runtime_error("No code table delimiter found | decompressFromSingleFile");
    }

    // 3. 读取剩余的二进制压缩数据
    vector<uint8_t> compressedData;
    uint8_t byte;
    while (singleFile.get(reinterpret_cast<char&>(byte))) {
        compressedData.push_back(byte);
    }
    singleFile.close();

    // 4. 解压数据（复用原有逻辑）
    BitReader bitReader(compressedData);
    string decompressedContent;
    string currentCode;
    long decodedCount = 0;

    while (bitReader.hasNext() && decodedCount < totalChars) {
        currentCode += bitReader.readBit();
        auto it = codeToCharMap.find(currentCode);
        if (it != codeToCharMap.end()) {
            decompressedContent += it->second;
            decodedCount++;
            currentCode.clear();
        }
    }

    // 5. 写入解压文件
    ofstream decompressedFile(decompressedFilepath, ios::binary);
    if (!decompressedFile.is_open()) {
        throw runtime_error("Decompressed file open failed | decompressFromSingleFile");
    }
    decompressedFile << decompressedContent;
    decompressedFile.close();
}