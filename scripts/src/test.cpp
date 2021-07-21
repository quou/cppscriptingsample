#include <engine.hpp>

class ENGINE_API SomeScript : public engine::ScriptBase {
private:
	float thing;
public:
	static engine::ScriptBase* ENGINE_CALL get_instance() {
		return new SomeScript();
	}

	void on_update(double timestep) override {
		engine::some_useful_function();
		printf("%g\n", timestep);
	}
};