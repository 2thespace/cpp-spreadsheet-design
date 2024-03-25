#pragma once

#include "common.h"
#include "formula.h"

class Cell : public CellInterface {
public:
    Cell();
    ~Cell();

    void Set(std::string text);
    void Clear();

    Value GetValue() const override;
    std::string GetText() const override;
    optional<double> GetHash();
    void SetHash();
    std::forward_list<Cell*> GetBackwardList();
private:
    class Impl;
    class EmptyImpl;
    class TextImpl;
    class FormulaImpl;
    std::unique_ptr<Impl> impl_;
    std::optional<double> hash_;
    std::forward_list<Cell*> backward_cell_;
};