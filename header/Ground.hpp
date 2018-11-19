#ifndef GROUND_HPP
#define GROUND_HPP

class Ground
{
  protected:
    static unsigned int ground_number;
    unsigned int ground_id;

  public:
    Ground();
    ~Ground();
    
    unsigned int getGroundId() const noexcept;
    void setGroundId(const unsigned int) noexcept;

};

#endif
