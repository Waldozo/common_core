#!/bin/bash

echo "=== Test minishell sans environnement ==="
echo "env" | env -i ./minishell
echo ""
echo "=== Test cd ==="
echo -e "env\ncd /tmp\nenv\nexit" | env -i ./minishell
