/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_SRC_GREENLAND_TARGET_CODEGEN_MACHINE_H_
#define ART_SRC_GREENLAND_TARGET_CODEGEN_MACHINE_H_

#include "dex_lang.h"

#include "instruction_set.h"

namespace art {
  class CompiledMethod;
  class OatCompilationUnit;
}

namespace llvm {
  class Function;
}

namespace art {
namespace greenland {

class Greenland;
class TargetLIREmitter;
class RegisterAllocator;
class TargetAssembler;

class TargetCodeGenMachine {
 protected:
  TargetCodeGenMachine() { }

 public:
  virtual ~TargetCodeGenMachine() { }

  virtual TargetLIREmitter* CreateLIREmitter(const llvm::Function& func,
                                             const OatCompilationUnit& cunit,
                                             DexLang::Context& dex_lang_ctx) =0;

  virtual RegisterAllocator* GetRegisterAllocator() = 0;

  virtual TargetAssembler* GetAssembler() = 0;

  static TargetCodeGenMachine* Create(InstructionSet insn_set);

 public:
  CompiledMethod* Run(const Greenland& parent,
                      const llvm::Function& func,
                      const OatCompilationUnit& cunit,
                      DexLang::Context& dex_lang_ctx);
};

} // namespace greenland
} // namespace art

#endif // ART_SRC_GREENLAND_TARGET_CODEGEN_MACHINE_H_
