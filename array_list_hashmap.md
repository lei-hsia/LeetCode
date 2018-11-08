### java: list & array change
1. Java: list to array: ```li.toArray()```, 是一个普通方法
2. Java. array to list: ```Arrays.asList(arr)```, 是一个static method; 导入util.Arrays.asList: ```import java.util.Arrays.asList/ import java.util.```
3. Java sort an array: ```Arrays.sort(arr)```
4. java sort a list: ```Collections.sort(li)```

### python: Numpy array->list

python: Numpy中的 ndarray to python list: np.array(...).tolist()

### java.hashmap

1. only interested in keys: iterate through keySet() of map:

```
Map<String, Object> map = ...;
for (String key: map.keySet()) {}
```
2. only interested in values: iterate through values() of map:

```
for (Object value: map.values()) {}
```
3. want both key and value, use```entrySet()```:

```
for (Map.Entry<String, Object> entry: map.entrySet()){
	String key = entry.getKey();
	Object value = entry.getValue();
}
```

1. 只想要key: ```keySet()```
2. 只想要values: ```values()```
3. 整个entry:   ```entrySet();  entry.getKey(); entry.getValue()```

HashMap methods:

```
void clear();
boolean containsKey(Object key);
boolean containsValue(Object value);
Object clone();
boolean isEmpty();
Set entrySet();:  
	entry.getKey(), entry.getValue();
Object get(Object key);
Set keySet();
int size();
Object put(Object key, Object value);
putAll(Map M);
Object remove(Object key);
Collection values();
```