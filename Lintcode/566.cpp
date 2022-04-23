/* Definition of BaseGFSClient
 * class BaseGFSClient {
 * private: map<string, string> chunk_list;
 * public:
 *     string readChunk(string& filename, int chunkIndex) {
 *         // Read a chunk from GFS
 *     }
 *     void writeChunk(string& filename, int chunkIndex,
 *                     string& content) {
 *         // Write a chunk to GFS     
 *     }
 *  };
 */


class GFSClient : public BaseGFSClient {
private:
    int chunkSize;
    unordered_map<string, int> filename2chunks;
public:
    /*
    * @param chunkSize: An integer
    */GFSClient(int chunkSize) {
        // do intialization if necessary
        assert(chunkSize > 0);
        this->chunkSize = chunkSize;
    }

    /*
     * @param filename: a file name
     * @return: conetent of the file given from GFS
     */
    string read(string &filename) {
        // write your code here
        auto iter = filename2chunks.find(filename);
        string content;
        if (iter != filename2chunks.end()) {
            for (int i = 0; i < iter->second; ++i) {
                content += readChunk(filename, i);
            }
        }
        return content;
    }

    /*
     * @param filename: a file name
     * @param content: a string
     * @return: nothing
     */
    void write(string &filename, string &content) {
        // write your code here
        int n = (int)content.size();
        int chunks = 1;
        if (n > chunkSize) {
            if (n % chunkSize == 0) {
                chunks = n / chunkSize;
                for (int i = 0; i < chunks; ++i) {
                    string str = content.substr(i*chunkSize, chunkSize);
                    writeChunk(filename, i, str);
                }
            } else {
                chunks = n / chunkSize + 1;
                for (int i = 0; i < chunks-1; ++i) {
                    string str = content.substr(i*chunkSize, chunkSize);
                    writeChunk(filename, i, str);
                }
                string str = content.substr(chunkSize*(chunks-1), n - chunkSize*(chunks-1));
                writeChunk(filename, chunks-1, str);
            }
        } else {
            writeChunk(filename, 0, content);
        }
        filename2chunks[filename] = chunks;
    }
};