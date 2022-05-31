from node import Node


def get_codes_for_characters_in_message(message: str):
    nodes = get_nodes(message)
    while len(nodes) > 1:
        nodes = sorted(nodes, key=lambda n: n.freq)

        left, right = nodes[0], nodes[1]
        left.bit, right.bit = 0, 1

        newNode = Node(left.symbol + right.symbol, left.freq + right.freq, left, right)

        nodes.remove(left)
        nodes.remove(right)
        nodes.append(newNode)
    codes = []
    assign_codes_to_nodes(nodes[0], codes)
    return sorted(codes, key=lambda node: node.freq, reverse=True)


def get_nodes(message: str) -> ():
    nodes = []
    for symbol in message:
        if symbol_is_in_node(symbol, nodes):
            nodes[nodes.index(Node(symbol))].inc()
        else:
            nodes.append(Node(symbol))
    return nodes


def symbol_is_in_node(symbol: str, nodes: list[Node]):
    for node in nodes:
        if node.symbol == symbol:
            return True
    return False


def assign_codes_to_nodes(node: Node, codes: list, code=''):
    new_code = code + str(node.bit)

    if node.left_child:
        assign_codes_to_nodes(node.left_child, codes, new_code)
    if node.right_child:
        assign_codes_to_nodes(node.right_child, codes, new_code)
    else:
        node.code = new_code
        codes.append(node)
