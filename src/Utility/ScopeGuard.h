// [B-OPENSOURCE] 第一方开源件 —— **勿逆向**。
// 这是 WindTerm 作者以 Apache-2.0 开源的一手组件(基于上游 ptyqt / 自研),不是反编译对象;
// 移植或修改须按 docs/calibration.md 逐句同构记录。分类依据见 src/README.md §1b。

 /*
 * Copyright 2020, WindTerm.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SCOPEGUARD_H
#define SCOPEGUARD_H

class ScopeGuard {
	typedef std::function<void()> GuardFunction;

public:
	ScopeGuard(GuardFunction acquire, GuardFunction release)
		: m_active(true)
		, m_release(std::move(release))
	{
		acquire();
	}

	~ScopeGuard() {
		if (m_active) {
			m_release();
		}
	}

	ScopeGuard() = delete;
	ScopeGuard(const ScopeGuard &) = delete;
	ScopeGuard &operator=(const ScopeGuard &) = delete;

	ScopeGuard(ScopeGuard &&other)
		: m_active(other.m_active)
		, m_release(std::move(other.m_release))
	{
		other.cancel();
	}

	void cancel() {
		m_active = false;
	}
	
private:
	bool m_active;
	GuardFunction m_release;
};

#endif // SCOPEGUARD_H
