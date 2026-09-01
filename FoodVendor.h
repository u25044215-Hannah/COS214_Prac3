/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Concrete Leaf representing a Lentedag food vendor.

 */
class FoodVendor : public EventUnit {
public:

    /**
     * @brief Construct a food vendor.
     *
     * @param name Human-readable vendor name.
     */
    explicit FoodVendor(const std::string& name);

    /**
     * @brief Virtual destructor.
     */
    virtual ~FoodVendor() {}

    /**
     * @brief Respond to a festival Notice.
     *
     * @param notice Notice pushed to the vendor.
     */
    virtual void update(const Notice& notice);
};
