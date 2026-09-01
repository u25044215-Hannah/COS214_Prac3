/*u25571878: Kelly Rademeyer
u25044215: Hannah diedrick
u25038967: Shelby bodenstein
*/
/**
 * @brief Concrete Leaf representing a Lentedag security and crowd-control post.
 */
class SecurityPost : public EventUnit {
public:

    /**
     * @brief Construct a security post.
     *
     * @param name Human-readable security-post name.
     */
    explicit SecurityPost(const std::string& name);

    /**
     * @brief Virtual destructor.
     */
    virtual ~SecurityPost() {}

    /**
     * @brief Respond to a festival Notice.
     *
     * @param notice Notice pushed to this security post.
     */
    virtual void update(const Notice& notice);

private:

    /**
     * @brief true when the post is managing evacuation/exit flow.
     */
    bool exitMode;
};
