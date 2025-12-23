#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <functional>

// --- Rosetta Core Architecture Mock ---

class Mover {
public:
    virtual ~Mover() = default;
    virtual void apply() = 0;
    virtual std::string get_name() const = 0;
};

// Creator function typedef
using MoverCreator = std::function<std::shared_ptr<Mover>()>;

class MoverFactory {
public:
    static MoverFactory& get_instance() {
        static MoverFactory instance;
        return instance;
    }

    void register_mover(const std::string& name, MoverCreator creator) {
        creators_[name] = creator;
        std::cout << "[Factory] Registered mover: " << name << std::endl;
    }

    std::shared_ptr<Mover> new_mover(const std::string& name) {
        auto it = creators_.find(name);
        if (it != creators_.end()) {
            std::cout << "[Factory] Creating new instance of: " << name << std::endl;
            return it->second();
        }
        std::cerr << "[Factory] Error: Mover not found: " << name << std::endl;
        return nullptr;
    }

private:
    std::map<std::string, MoverCreator> creators_;
    MoverFactory() = default;
};

// --- Antigravity Protocol Implementation ---

class AntigravityMover : public Mover {
public:
    void apply() override {
        std::cout << "[AntigravityMover] APPLYING: Reversing gravity field..." << std::endl;
        std::cout << "[AntigravityMover] SUCCESS: Target is now weightless." << std::endl;
    }

    std::string get_name() const override {
        return "AntigravityMover";
    }

    static std::shared_ptr<Mover> create() {
        return std::make_shared<AntigravityMover>();
    }
};

class NullMover : public Mover {
public:
    void apply() override {
        std::cout << "[NullMover] Doing nothing." << std::endl;
    }
    std::string get_name() const override { return "NullMover"; }
    static std::shared_ptr<Mover> create() { return std::make_shared<NullMover>(); }
};


// --- Simulation ---

int main() {
    std::cout << "--- Rosetta Protocol Factory Mock ---" << std::endl;

    // 1. Registration Phase (Static initialization simulation)
    MoverFactory::get_instance().register_mover("AntigravityMover", AntigravityMover::create);
    MoverFactory::get_instance().register_mover("NullMover", NullMover::create);

    // 2. Client Usage (Simulating XML Protocol Parsing)
    std::string requested_protocol = "AntigravityMover";
    
    std::shared_ptr<Mover> protocol = MoverFactory::get_instance().new_mover(requested_protocol);

    if (protocol) {
        std::cout << "Successfully instantiated: " << protocol->get_name() << std::endl;
        protocol->apply();
    } else {
        std::cerr << "Protocol instantiation failed." << std::endl;
        return 1;
    }

    // 3. Negative Test
    std::cout << "\n--- Negative Test ---" << std::endl;
    auto bad_protocol = MoverFactory::get_instance().new_mover("NonExistentMover");
    if (!bad_protocol) {
        std::cout << "Correctly handled missing protocol." << std::endl;
    }

    return 0;
}
