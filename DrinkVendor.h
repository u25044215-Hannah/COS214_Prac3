/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Concrete Leaf representing a Lentedag beverage vendor or water point.

 */
class DrinkVendor : public EventUnit {
public:

    /**
     * @brief Construct a drink vendor.
     *
     * @param name Human-readable vendor name.
     */
    explicit DrinkVendor(const std::string& name);

    /**
     * @brief Virtual destructor.
     */
    virtual ~DrinkVendor() {}

    /**
     * @brief Respond to a festival Notice.
     *
     * @param notice Notice pushed to this drink vendor.
     */
    virtual void update(const Notice& notice);

private:

    /**
     * @brief Indicates whether the vendor is currently prioritising water.
     */
    bool waterPriority;
};
