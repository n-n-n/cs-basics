class Buffer {
public:
  void* read_block() = 0;
  void* get_data() = 0;
  void mark_dirty() = 0;
  void release_buffer() = 0;
};
class BufferPool_Message_Passing : public BufferPool
{
public:
  virtual void insert(void* p, int size, int pos) = 0;
  virtual void get_bytes(void *p, int size, int pos) = 0;
};

class BufferPool_Buffer_Passing : public BufferPool
{
public:
  virtual void* get_block(int block) = 0;
  virtual void dirty_block(int block) = 0;
  virtual int block_size() = 0;
};
