// https://www.nowcoder.com/practice/b7a8647e33d84f5c88acdd7c81a85fdf

function square(arr) {
	var newArr = arr.slice(0);
    for (var i = 0; i < arr.length; i++) {
        newArr[i] = arr[i] * arr[i];
    }
    return newArr;
}